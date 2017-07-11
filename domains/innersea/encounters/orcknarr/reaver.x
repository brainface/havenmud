// mahkefel april 2011
// bad dude does bad things stay away
#include <lib.h> 
#include <domains.h>                      
#include <std.h>                       
#include <damage_types.h>
#include "reaver.h"
inherit LIB_SHIPCAPTAIN;               

void heart_beat();

static void create() {
  ::create();         
  SetRace("orc");   
  SetGender("male");  
  SetClass("necromancer");  
  SetClass("viking");
  SetSkill("enchantment",1,1);
  SetLevel(130);        
  SetKeyName("reaver");
  SetId( ({ "reaver","orc" }) );
  SetShort("an orcish reaver");
  SetAdjectives( ({ "orcish" }) );
  SetLong(                                
    "This hulking brute's chest is marred by countless profane symbols scarred "
    "into his flesh, the evidence of service under an master even crueler than "
    " himself. His marred skin stretches taught over his muscles and sinew, as "
    "if he has gone long without a fresh meal."
  );                                                                          

  SetMorality(-1500);
  SetInventory( ([                                                            
    INNERSEA_ENCOUNTERS + "obj/broad_axe" : "wield axe",
    INNERSEA_ENCOUNTERS + "obj/sharkskin" : "wear my leggings",
  ]) );                                                                       

  SetCaptainAggressiveness(80);
  SetCombatAction(30, ({
     "!cast ice lance",
  }) );
  SetResistance(ALL_ELEMENTS|MAGIC,"low");//cheeeeaaatting
  SetProperty("pirate",1);                                                   
  SetShipWander(1);                                                           
  SetCurrency("orcteef", 20000);                                              
}                                                                             

/*
void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 1) {
    eventForce("cast veil from beyond");
  }
}*/

// level self when encountering player
int eventEncounterShip(object ship) { 
  object targ;                        
  int piratelevel;                    

  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }
  if(targ->GetProperty("pirate")){                 
    return 0;                                      
  }                                                
  piratelevel = targ->GetLevel();
  if(piratelevel > 500 ) { piratelevel = 500; }
  if(piratelevel < 150 ) { piratelevel = 150; }
  SetLevel( piratelevel - 20 );                                       
  return ::eventEncounterShip(ship);                                  
}                                                                     

string eventShipCombat(object *enemies) {
  object pirate;                         
  object vic;                            
  float x;                               
  object myship = environment();         
  object ship;                           
  int piratelevel;
    foreach(object e in enemies) {
      if (e) if (e->GetPilot())
        if (e->GetPilot()->GetProperty("pirate")) enemies -= ({ e });
      }
   if(sizeof(enemies) == 0) { return ::eventShipWander(); }
  ship = enemies[random(sizeof(enemies))];
        x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
        x = to_int(x); x -= ShipWimpy; x += CaptainAggressiveness;
  if (random(200) < x) { /* I am going to attack! */
   if (!random(5)) {
    vic = ship->GetPilot();
    if (!vic) { return ::eventShipCombat(enemies); }
    piratelevel = vic->GetLevel();
    pirate = new( REAVER_DIR "reaver" );
    if(piratelevel > 500 ) { piratelevel = 500; }
    pirate->SetLevel( piratelevel - 20);
    pirate->eventMove(myship);
    call_out( (: call_other, pirate, "eventForce", "out" :), 2 );
    call_out( (: call_other, pirate, "eventForce", "board " + ship->GetName():), 2 );
    call_out( (: call_other, pirate, "eventForce", "kill " + vic->GetKeyName():), 3 );
    return "Yell take the ship men, fresh meat for the cook pot! ";
   }
  }
  return ::eventShipCombat(enemies);
}


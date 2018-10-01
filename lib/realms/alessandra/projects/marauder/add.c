#include <lib.h>                       
#include <std.h>                       
#include <damage_types.h>              
#include "marauder.h"                  
inherit LIB_SHIPCAPTAIN;               

void heart_beat();

// pull npc out of combat and turn invis
void eventHide();                       

// become invis & backstab
void eventBackstab();     

// do special thingy what hurts players
void eventSpecial();                   

// friend or foe??
int eventCheckPlayer();
int checkHostile(object target);

static void create() {
  ::create();         
  SetRace("dark-elf");   
  SetGender("male");     
  SetClass("sailor");    
  SetClass("fighter");   
  SetSkill("enchantment",1,1);
  SetLevel(140);              
  SetKeyName("add");          
  SetId( ({ "add","dude" }) );
  SetShort("an additional dude");
  SetAdjectives( ({ "additional" }) );
  SetLong(                                
    "This is an additional dude."                               
  );                                                                                                           
  SetInventory( ([                                                                                             
    STD_HACK "battle_axe" : "wield axe",                                                                       
  ]) );                                                                                                        
  SetCaptainAggressiveness(110);                                                                               
  SetAction(80, ({                                                                                             
      "!laugh evilly",                                                                                         
  }) );                                                                                                        
  /*SetCombatAction(30, ({                                                                                     
                                                                                                               
  }) );*/                                                                                                      
  SetResistance(ALL_ELEMENTS|MAGIC,"low");//cheeeeaaatting                                                     
  SetProperty("pirate", 1);                                                                                    
  SetShipWander(1);                                                                                            
  SetCurrency("rounds", 20000);                                                                                
  SetEncounter( (:eventCheckPlayer:) );
  SetReligion("Soirin");
  SetTown("Malveillant");
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
  SetLevel( piratelevel - 20 );
  return ::eventEncounterShip(ship);
}

string eventShipCombat(object *enemies) {
  return ::eventShipCombat(enemies);
}


void eventSpecial() {

}

int eventCheckPlayer() {
  object who = this_player();                         
  object pirate;                                      
  int piratelevel;                                    
  if (!checkHostile(who)) {            
    return 0;                                         
  }                                                   
  SetAttack(who);                                     
  return 1;    
}

// returns 0 if friendly to target,
// returns 1 if hostile to target
int checkHostile(object target) {
  if(
    target->GetProperty("pirate")
    || target->GetRace()=="dark-elf"
    || target->GetReligion()=="Soirin"
  ) {
    debug("add is not hostile to: "+target->GetName());
    return 0;
  }
  debug("add is hostile to: "+target->GetName());
  return 1;
}



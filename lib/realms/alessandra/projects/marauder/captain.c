#include <lib.h>                                                                                    
#include <domains.h>                                                                                
#include <std.h>                                                                                    
#include <damage_types.h>                                                                           
#include <daemons.h>                                                                                
#include "marauder.h"                                                                               
inherit LIB_SHIPCAPTAIN;                                                                            

int eventCheckPlayer();                                                                             
void heart_beat();                                                                                  
void eventSpecial(object ship);                                                                     
void eventBoarder(object ship);                                                                     
int checkHostile(object target);                                                                    
object *pirates;                                                                                    

static void create() {
  ::create();         
  SetKeyName("basic captain");
  SetShort("a basic captain (dark-elf)");
  SetId( ({ "captain" }) );              
  SetAdjectives( ({ "basic" }) );        
  SetRace("dark-elf");                           
  SetTown("Malveillant");                        
  SetReligion("Soirin");                         
  SetClass("sailor");                            
  SetMorality(-500);
  SetLevel(150);                                 
  SetLong(                                       
    "Basically, a captain."                      
  );                                             
  SetGender("female");                                                            
  SetCaptainAggressiveness(150);                                                  
  SetInventory( ([                                                                
    STD_WEAPON + "hack/meat_hook" : "wield hook",                                 
  ]) );                                                                           
  SetProperty("pirate", 1);                                                       
  SetShipWander(1);                                                               
  SetCurrency("rounds", 20000);                                                   
  SetEncounter( (:eventCheckPlayer:) );                                           
  pirates = ({ });                                                                
  SetCombatAction(50, (:eventSpecial:) );                                         
  SetFriends( ({"add","donnie"}) );
}                                                                                 

void heart_beat() {
  ::heart_beat();  
  //TODO: protections, etc.
}                          

// will not attack pirates, dark elves, or soirin ships
int eventEncounterShip(object ship) {                  
  object targ;                                         
  int piratelevel;                                                        
  targ = ship->GetPilot();                                                
  if (!targ) { return ::eventEncounterShip(ship); }                       
  if(targ->GetProperty("pirate")                                          
    || targ->GetRace("dark elf")                                          
    || targ->GetReligion("Soirin")                                        
  ){                                                                      
    return 0;                                                             
  }                                                                       
  piratelevel = targ->GetLevel();                                         
  if(piratelevel > 500 ) { piratelevel = 500; }                           
  SetLevel( piratelevel + random(10) );                                           
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
   if (!checkHostile(e)) enemies -= ({ e });
  }                                                             
  if(sizeof(enemies) == 0) { return ::eventShipWander(); }      
    ship = enemies[random(sizeof(enemies))];                    
    x = (100.0 * myship->GetDamagePoints()) / myship->GetMaxDamagePoints();
    x = to_int(x); x -= ShipWimpy; x += CaptainAggressiveness;             
  if (random(200) < x) {                                                   
    // I am going to attack!                                               
    // 1 out of five: spawn boarder                                        
    //switch(random(5)) {                                                  
    switch (random(3)) {                                                           
      case 0:                                                              
        debug("captain is sending assassin");                              
        eventBoarder(ship);                                                
        break;                                                             
      case 1 .. 4:                                                         
        debug("captain is doing nothing special");                         
    }                                                                      
  }                                                                        
  return ::eventShipCombat(enemies);                                       
}                                                                          

// will allow soirin, or dark elves to peaceably board
int eventCheckPlayer() {                              
  object who = this_player();                         
  object pirate;                                      
  int piratelevel;                                    
  if (!checkHostile(who)) {            
    return 0;                                         
  }                                                   
  SetAttack(who);                                     
  piratelevel = who->GetLevel();                      
  pirate = new( MARAUDER_DIR "add" );                 
  if(piratelevel > 500 ) { piratelevel = 500; }       
  pirate->SetLevel( piratelevel - random(10));        
  pirate->eventMove(environment());                   
  pirate->eventForce("kill " + who->GetKeyName());    
  return 1;                                           
}                                                     

// do something special
void eventSpecial(object ship) {
  return;                       
}                               

// send over a boarder
//  thisnboarder works a bit different, only 1 boarder is ever sent,
//  but he is designed to be tougher.                               
void eventBoarder(object ship) {                                    
  object vic, pirate;                                               
  int piratelevel;                                                  
  //TODO: send only 1 boarder (per ship?)                             
  vic = ship->GetPilot();                                                
  if (!vic) {return; }                                                   
  if (GetProperty("assassinate_"+vic->GetName())) {                      
    debug("assassination target already set, don't send another");       
    return;                                                              
  } else {
    SetProperty("assassinate_"+vic->GetName(),1);
    debug("setting assassination target: "+vic->GetName());
  }
  piratelevel = vic->GetLevel();
  pirate = new( MARAUDER_DIR "donnie" );
  if(piratelevel > 500 ) { piratelevel = 500; }
  pirate->SetLevel( piratelevel + random(10) );
  //TODO set invisible
  pirate->eventMove(ship);
  call_out( (: call_other, pirate, "eventForce", "backstab " + vic->GetKeyName() :), 2 );
  return;
}

// returns 0 if friendly to target,
// returns 1 if hostile to target
int checkHostile(object target) {
  if(
    target->GetProperty("pirate")
    || target->GetRace()=="dark-elf"
    || target->GetReligion()=="Soirin"
  ) {
    debug("captain is not hostile");
    return 0;
  }
  debug("captain is hostile");
  return 1;
}


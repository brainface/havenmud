// changed by Mahkefel 2010
//    made level to player, up to level 300
//    cleaned up some behavior             
//    fucker will only call his minions from the hold on
//      his own damn ship.                              
//    added awesome weapon                              
#include <lib.h>                                        
#include <domains.h>                                    
#include <std.h>                                        
#include <damage_types.h>                               
#include <domains.h>                                    
inherit LIB_PIRATE;                                     

void DoAction();                                        

static void create() {
  ::create();         
  SetKeyName("skeletal captain");
  SetShort("a skeletal captain (undead)");
  SetId( ({ "captain", "pirate", "human", "undead" }) );
  SetAdjectives( ({ "pirate", "human", "skeletal", "undead" }) );
  SetRace("human");                                              
  SetClass("viking");                                            
  SetSkill("enchantment", 1, 1);                                 
  SetUndead(1);                                                  
  SetLevel(150);                                                 
  SetLong(                                                       
    "This unsightly creature used to be a human pirate. Now undead, he is "
    "composed almost entirely of bone, save a few scraps of tattered, dead "
    "skin. Lacking any recognizable physical features, he is identifiable as "
    "captain by a black eyepatch over his right eye socket."                  
    );                                                                        
  SetGender("male");                                                          
  SetCaptainAggressiveness(110);                                              
  SetProperty("pirate", "undead");                                             
  SetShipWander(1);                                                            
  SetInventory( ([                                                             
    DOMAIN_INNERSEA "encounters/undead/captain_cutlass" : "wield shimmering cutlass",
    DOMAIN_INNERSEA "encounters/undead/cutlass" : "wield rusty cutlass",             
  ]) );                                                                              
  SetFirstCommands( ({ "wield all" }) );                                             
  SetCurrency("imperials", 2000);                                                    
  SetCombatAction(35, (: DoAction :) );                                              
  SetNoCorpse(1);                                                                    
  SetDie("The pirate turns to dust and disperses on the wind.");                     
  SetResistance(ALL_PHYSICAL|MAGIC, "medium");                                       
  SetResistance(ALL_ELEMENTS, "high");                                               
  SetResistance(COLD|POISON|HUNGER|DISEASE, "immune");                               

  SetBoarder(INNERSEA_ENCOUNTERS "undead/skeletonpirates");
  SetFirstMate(INNERSEA_ENCOUNTERS "undead/skeletonpirates");
  SetPassengerAttacker(INNERSEA_ENCOUNTERS "undead/chainedzombie");
  SetMinLevel(135);
  SetMaxLevel(300);                                                
}                                                                  

varargs int eventDie(object agent) {
  if (agent) agent->AddTitle("the Despoiler of the Black Night");
  return ::eventDie(agent);                                      
}                                                                

void DoAction() {
  object who = this_object();
  object pirate;             

  if (environment()) {
    if (!environment()->GetKeyname("black night")) {
      return;                                       
    }                                               
  }                                                 
  message("enter", "An undead pirate rushes to the aid "
    "of the Captain.", environment(who));               
  pirate = new( GetFirstMate() );                       
  pirate->SetLevel( who->GetLevel() - 10);              
  pirate->eventMove(environment());                     
  call_out( (: call_other, pirate, "eventForce", "yell protect the captain!" :), 2 );
} 

//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Teh Mitey Krakn Captain
//

#include <lib.h>      
#include <domains.h>  
#include <std.h>      
#include <daemons.h>     
#include "../dalnairn.h"                     

inherit LIB_PIRATE;

static void create() {

  ::create();         
  SetKeyName("gellekros");
  SetId( ({ "kobold" }) );    
  SetAdjectives( ({ "tall" }) );
  SetRace("kobold");                                  
  SetTown("Arcanith");
  SetClass("viking");
  SetSkill("berserking", 1, 1); 
  SetSkill("disorient", 1, 1);                                              
  SetMorality(0);                                           
  SetReligion("Magildan");                                     
  SetLevel(150);
  SetShort("gellekros the Captain (kobold)");                                       
  SetLong(                                                      
    "A tall kobold with axes. ouch!"  
  );                                                                          
  SetGender("male");                                                        
  SetCaptainAggressiveness(150);
  SetMinLevel(100);
  SetMaxLevel(500);                                            
  SetInventory( ([
    STD_CLOTHING "small_shirt" : "wear shirt",
    STD_CLOTHING "small_pants" : "wear pants",
    STD_CLOTHING "small_shoes" : "wear shoes",
    STD_CLOTHING "small_coat" : "wear coat",
    STD_WEAPON "hack/hand-axe" : "wield axe",
    STD_WEAPON "slash/sword" : "wield sword",
    STD_ARMOUR "free_armour/small/oldboots" : "wear boots",
    STD_ARMOUR "free_armour/small/oldpants" : "wear pants",
//    DAL_ARM "tentacle_outfit" : "wear my outfit on torso and "
//        "upper right arm and right leg and upper left arm and left leg",
  ]) );                                                                          
  SetCurrency("shards", 1500 + random (500) );                                   
  SetProperty("pirate", 1);    
  SetFirstCommands( ({
    "wield all",
    "board krakn"
  }) );
  SetAction(10, ({ 
    "!board krakn"
  }) );                                                        
  SetCombatAction(40, ({                                                         
     "!disorient",                                                       
     "!cleave",                                                          
     "!frenzy",  
     "!disarm",
     "!massacre",                                                               
  }) );             
//  SetBoarder( DAL_NPC "kobold_boarder" );
//  SetPassengerAttacker( DAL_NPC "kobold_passanger" );
//  SetFirstMate( DAL_NPC "kobold_firstmate" );        
}           

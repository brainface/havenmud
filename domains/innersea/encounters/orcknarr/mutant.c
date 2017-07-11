// mahkefel april 2011
// goblin mutant kills your passengers
#include <lib.h>                      
#include <domains.h>                      
#include <std.h>                          
#include <armour_types.h>                          
#include <damage_types.h>                          
#include "reaver.h"                                
inherit LIB_PIRATE;                                

void heart_beat();

static void create() {
  ::create();         
  SetRace("goblin");     
  DestLimb("left hand"); 
  DestLimb("right hand");
  AddLimb("second head","torso",1);
  AddLimb("upper right tentacle","torso",4,({A_WEAPON}) );
  AddLimb("lower right tentacle","torso",4,({A_WEAPON}) );
  AddLimb("left tentacle","torso",4,({A_WEAPON}) );       
  SetGender("male");                                      
  SetClass("viking");                                     
  SetSkill("enchantment",1,1);                            
  SetLevel(1);                                            
  SetKeyName("mutant");                                   
  SetId( ({ "mutant","goblin" }) );                       
  SetShort("a two-headed goblin mutant");                 
  SetAdjectives( ({ "goblin","two-headed" }) );           
  SetLong(                                                
    "This pathetic little creature has been mutated by magic beyond his ken "
    "into an instrument of SaaHaGoth. His flippered hands dangle uselessly, "
    "and octupus tentacles twitch menacingly from his sides. A second "
    "head grows from his shoulders, growling and snarling at all around him."
  );

  SetMorality(-1500);
  SetInventory( ([
    INNERSEA_ENCOUNTERS + "obj/belaying_pin" : 3,
  ]) );
  SetFirstCommands( ({
    "wield pins"
  }) );
  SetCaptainAggressiveness(80);
  SetAction(5, ({
    "!emote slams his two heads together.",
    "!emote twitches."
  }) );
  SetCombatAction(30, ({
     "!disorient",
     "!emote snarl",
     "!emote whimpers piteously",
  }) );
  SetResistance(ALL_ELEMENTS|MAGIC,"low");//cheeeeaaatting
  SetProperty("pirate","orc");
  SetShipWander(1);
  SetCurrency("orcteef", 10000);

  SetTown("Karak");
  SetReligion("Saahagoth");
  SetMinLevel(1);
  SetMaxLevel(500);
}

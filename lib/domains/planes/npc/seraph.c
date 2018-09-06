/* A holy scion */
//  mahkefel mar '10
//    added armour  
//    changed size to medium
//    (to make loot useful to
//     medium people)        
// 2018: angel race
#include <lib.h>             
#include "../planes.h"       
#include <damage_types.h>    
#include <armour_types.h>    
#include <size.h>            
inherit LIB_NPC;             

static void create() {
  npc::create();      
  SetKeyName("seraph");
  SetShort("a graceful seraph");
  SetId( ({ "seraph" }) );       
  SetAdjectives( ({ "graceful" }) );
  SetLong(
    "This creature looks like a beautiful elven maiden, but twice as tall as "
    "any elf has a right to be, and with six graceful wings sprouting from her "
    "back."
  );                                         
  SetGender("female");                       
  SetRace("angel");                 
  AddLimb("upper left wing", "torso", 2, ({A_WING}));
  AddLimb("upper right wing", "torso", 2, ({A_WING}));
  AddLimb("lower left wing", "torso", 2, ({A_WING})); 
  AddLimb("lower right wing", "torso", 2, ({A_WING}));
  SetClass("bard");                                     
  SetLevel(80);

  SetAction( 10, ({ 
    "!emote leaps into the air and does a mid-air cartwheel.",
    "!emote slowly folds and unfolds her wings one by one.",    
    "!emote sounds a few radiant notes.",    
    "!emote sounds a hesitant note, then slightly adjusts a slide on her trumpet.",
    "!say shhh I'm about to sing about The Lord.",
  }) );                                       
  SetCombatAction( 40, ({
    "!say Go away! You don't belong here!",                             
    "!sing song of the dance",                        
    "!sing star strike",                              
    "!sing aria of angels",
    "!sing vibrations of destruction",
  }) );
  SetFirstCommands( ({
    "wear first tabard on upper right wing",
    "wear first tabard on upper left wing",
    "sing aural shield",
  }) );
  SetInventory( ([
     PLANE_OBJ + "seraph_trumpet" : "wield trumpet",
     PLANE_OBJ + "seraph_tunic" : "wear tunic on torso and right arm and left arm and right leg and left leg",
     PLANE_OBJ + "seraph_wing" : 2,
     //  "wear tunic on torso and right arm and left arm and right leg and left leg",
  ]) );
  SetMorality(2000);
  SetReligion("Kylin");

  // neccessary
  SetSongBook(([
    "aural shield" : 100,
    "song of the dance" : 100,
    "star strike" : 100,
    "aria of angels" : 100,
    "vibrations of destruction" : 100,
  ]) );

  SetDie("A graceful seraph wails tunelessly and collapses in a broken heap of wings.");
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
      eventForce("sing aural shield");
  }
}



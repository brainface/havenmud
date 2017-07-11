/* A harpy thing */
//  mahkefel mar '10
//    added armour
//    changed size to medium
//    (to make loot useful to
//     medium people)
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("harpy");
  SetShort("a curious harpy");
  SetId( ({ "harpy" }) );
  SetAdjectives( ({ "curious" }) );
  SetLong( 
    "This large feathered creature appears to be some mythical cross between a "
    "woman and a raptor. Two immense, tawny wings extend from her back, and "
    "her legs end in razor sharp talons instead of feet. The expression on "
    "her face seems more curious than malicious, though."
  );
  SetGender("female");
  SetRace("devil", "harpy");
  SetBaseLanguage("archaic");
  DestLimb("left foot");
  DestLimb("right foot");
  AddLimb("left wing", "torso", 2, ({A_WING}) );
  AddLimb("right wing", "torso", 2, ({A_WING}) );
  AddLimb("left talons", "left leg", 2, ({A_WEAPON}) );
  AddLimb("right talons", "right leg", 2, ({A_WEAPON}) );
  SetClass("bard");
  SetSkill("brawling",1);
  SetLevel(80);

  SetAction( 15, ({
    "!emote %^BOLD%^YELLOW%^SCREEEECHES%^RESET%^ painfully.",
    "!emote pounces upon a furry thing and begins consuming it noisily.",
    "!ask Can you sing me a song, wingless one?",
    "!ask What's a cute little flightless bird like you doing in a plane like this?",
    "!say Oh, sure, we used to just grab travellers willy nilly and take them back "
      "to the nest for husbands. But we all decided that was uncivilized.",
    "!emote preens for you.",    
    "!emote launches herself into the air in a flurry of feathers.",
    "!emote glides slowly around while watching you curiously.",
  }) );
  SetCombatAction( 40, ({
    "!say This isn't very nice of you!",
    "!say I was going to take you back to the nest, but not if you're going to be like this!",
    "!sing ballad of the seasons",
    "!sing song of the dance",
    "!uppercut", // lol
  }) );
  SetFirstCommands( ({
    "wear first hide on right wing",
    "wear first hide on left wing",
    "wield first talon in left talons",
    "wield first talon in right talons",
  }) );
  SetInventory( ([
     PLANE_OBJ + "harpy_flute" : "wield flute in right hand",
     PLANE_OBJ + "harpy_dress" : "wear dress on torso and right arm and left arm and right leg and left leg",
     PLANE_OBJ + "harpy_wing" : 2,
     PLANE_OBJ + "harpy_claw" : 2,
     
     //  "wear tunic on torso and right arm and left arm and right leg and left leg",
  ]) );
  SetMorality(0);
  //SetReligion("Kylin");

  // neccessary
  SetSongBook(([
    "ballad of summer" : 100,
    "ballad of winter" : 100,
    "ballad of fall" : 100,
    "ballad of spring" : 100,
    "wail of the banshee" : 100,
    "song of the dance" : 100,
  ]) );

  SetDie("A harpy crashes to the ground, confusion and hurt writ on her "
    "dying face.");
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
      eventForce("sing wail of the banshee");
  }
}


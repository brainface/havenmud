/*  A lamrani greater mage */
#include <lib.h>
#include <std.h>
#include "../temple.h"
inherit LIB_LEADER;

static void create() {
  ::create(); 
  SetKeyName("lamrani master");
  SetLimit(1);
  SetRace("lamrani");
  SetMorality(600);
  SetFriends( ({ "lamrani_temple_npc" }) );
  SetGender("male");
  SetShort("a lamrani master adept");
  SetId( ({ "lamrani_temple_npc", "adept", "lamrani", "master" }) );
  SetAdjectives( ({ "lamrani", "master" }) );
  SetClass("evoker");
  SetSkill("shock magic",1,1);
  SetSkill("fire magic",1,1);
  SetSkill("necromancy",1,1);
  SetTown("First Lower Plane");
  SetLevel(random(80) + 125);
  SetSpellBook( ([
    "enhanced energy wall" : 100,
    "disintegrate"         : 100,
    "paralysis"            : 100,
    "chain lightning"      : 100,
    "flamestrike"          : 100,
    "planar durability"    : 100,
    "planar strength"      : 100,
    "death"                : 100,
    "temperature shield"   : 100,
    ]) );
  SetLong("This lamrani is a Master Adept of Lamrani magic. "
          "His pasty white skin seems to exude power, while "
         "the marks of magical mastery emblazoned on his "
         "hairless head give him a look that would scare off "
         "most mortals stupid enough to challenge his supremacy "
         "in his temple.");
  SetAction(5, ({
      "!yell My Brethren, we will return to glory!",
      "!emote seems to float aimlessly.",
      "!emote mutters a little prayer.",
      }) );
  SetCombatAction(85, ({
      "!yell Brethren, we are under attack!",
      "!cast chain lightning",
      "!cast flamestrike",
      "!cast death",
      }) );
  SetInventory( ([
    STD_CLOTHING + "body/crimson_robe" : "wear robe",
    TEMPLE_OBJ   + "master_staff"      : "wield staff",
    ]) );
  SetMessage("leave", "$N floats $D effortlessly.");
  SetMessage("come", "$N floats in effortlessly.");
  SetWander(10);
  SetFirstCommands( ({
  	"cast enhanced energy wall",
  	"cast enhanced energy wall",
        "cast temperature shield",
  	"cast temperature shield",
  	"cast temperature shield",
  	"cast planar durability",
  	"cast planar strength",
  	}) );
  	
  	
  	
  SetNoJoin(1);
 }

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast temperature shield");
  }
}

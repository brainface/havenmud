/*  A ninja using a kusari-gama */
#include <lib.h>
#include <std.h>
#include "../tairi.h"
//inherit LIB_STYLE_TRAINER;
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("old man");
  SetShort("a grey-robed man");
  SetRace("human");
//  SetRaceRestricted( ({ "dwarf", "lamrani", "orc" }) );
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("ninja");
  SetSkill("projectile combat", 1, 1);
  SetLevel(25);
  SetGender("male");
  SetId( ({ "man", "ninja" }) );
  SetAdjectives( ({ "grey", "robed", "ninja" }) );
  SetLong("This grey robed warrior from the valley lands of "
          "Tai-Ri seems to be sitting and contemplating his "
          "lot in life. He seems at peace with himself.");
  SetMorality(50);
  SetInventory( ([
      TAI_RI_OBJ + "kusarigama" : "wield axe",
      STD_CLOTHING + "body/gray_robe" : "wear robe",
    ]) );
  SetAction(5, ({
     "!sit down",
     "!emote sits absolutely motionless.",
     "The old man's ears perk up to some imperceptable noise.",
     "!speak The way of the warrior is long and difficult.",
     }) );
  SetCombatAction(5, ({
      "!yell Ayukan!",
    }) );
//  SetCombatStyleLevel("ninjitsu", 40);
//  SetCombatStyle("ninjitsu");
  call_out( (: eventForce, "sit down" :), 0);
}

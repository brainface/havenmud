/*  A ninja using a kusari-gama */
#include <lib.h>
#include <position.h>
#include <std.h>
#include "../ninja.h"
inherit LIB_STYLE_TRAINER;

static void create() {
  ::create();
  SetKeyName("old man");
  SetShort("a grey-robed man");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("ninja");
  SetLevel(35);
  SetGender("male");
  SetFriends( ({
     "guard","ninja"
  }) );
  SetId( ({ "man", "ninja" }) );
  SetAdjectives( ({ "grey", "robed", "ninja" }) );
  SetLong("This grey robed warrior from the valley lands of "
          "Tai-Ri seems to be sitting and contemplating his "
          "lot in life. He seems at peace with himself.");
  SetMorality(50);
  SetInventory( ([
     N_OBJ + "kusarigama" : "wield axe",
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
    "!cast vine wall",
    "!cast barkskin",
    "!cast solar charge",
    "!cast lunar charge",
    }) );
  SetCombatStyleLevel("ninjitsu", 100);
  SetCombatStyle("ninjitsu");
  SetPosition(POSITION_SITTING);
}

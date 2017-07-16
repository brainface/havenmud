/*  A ninja using a kusari-gama */
#include <lib.h>
#include "../tairi.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("ninja guard");
  SetShort("a dark-robed guard");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("rogue");
  SetSkill("projectile combat", 1, 1);
  SetLevel(25);
  SetGender("male");
  SetId( ({ "guard", "ninja" }) );
  SetAdjectives( ({ "dark", "robed", "ninja" }) );
  SetLong("This dark robed warrior from the valley lands of "
          "Tai-Ri seems to stand guard over the entrance to "
          "someplace important.");
  SetInventory( ([
      TAI_RI_OBJ + "kusarigama" : "wield axe",
      TAI_RI_OBJ + "shozoku"    : "wear shozoku",
    ]) );
  SetAction(5, ({
     "!emote stands absolutely motionless.",
     "The ninja's ears perk up to some imperceptable noise.",
     }) );
  SetCombatAction(5, ({
      "!yell NIIIIIINNNNNNJJJJJJAAAAAA!!!!!!",
      "!emote flicks his wrist in your direction.",
    }) );
  SetCombatStyleLevel("ninjitsu", 40);
  SetCombatStyle("ninjitsu");
}

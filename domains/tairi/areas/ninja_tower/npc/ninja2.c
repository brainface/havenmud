/*  A ninja using a kusari-gama */
#include <lib.h>
#include "../ninja.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("ninja guard");
  SetShort("a dark-robed guard");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("ninja");
  SetSkill("projectile combat", 1, 1);
  SetLevel(25);
  SetGender("male");
  SetFriends( ({
     "old man","ninja","guard"
  }) );
  SetId( ({ "guard", "ninja" }) );
  SetAdjectives( ({ "dark", "robed", "ninja" }) );
  SetLong("This dark robed warrior from the valley lands of "
          "Tai-Ri seems to stand guard over the entrance to "
          "someplace important.");
  SetInventory( ([
     N_OBJ + "ninjato" : 2,
     N_OBJ + "shozoku" : "wear shozoku",
    ]) );
  SetAction(5, ({
     "!emote stands absolutely motionless.",
     "The ninja's ears perk up to some imperceptable noise.",
     }) );
  SetCombatAction(5, ({
      "!yell NIIIIIINNNNNNJJJJJJAAAAAA!!!!!!",
      "!emote flicks his wrist in your direction.",
    }) );
  call_out( (: eventForce, "wield first knife" :), 0);
  call_out( (: eventForce, "wield first knife" :), 0);
  SetCombatStyleLevel("ninjitsu", 40);
  SetCombatStyle("ninjitsu");
}

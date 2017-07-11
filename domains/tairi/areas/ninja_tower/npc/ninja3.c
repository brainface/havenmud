/*  A ninja using a kusari-gama */
#include <lib.h>
#include "../ninja.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("ninja guard");
  SetShort("a dark-robed ninja");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("ninja");
  SetLevel(25);
  SetGender("male");
  SetId( ({ "guard", "ninja" }) );
  SetFriends( ({
     "old man","ninja","guard"
  }) );
  SetAdjectives( ({ "dark", "robed", "ninja" }) );
  SetLong(
     "This dark robed ninja is in a sparring session. He moves silently as he "
     "fights his opponent, yet keeps an eye on his surroundings as well. "
  );
  SetInventory( ([
     N_OBJ + "shozoku" : "wear shozoku",
    ]) );
  SetAction(5, ({
     "!emote snaps his wrist at his opponent. ",
     "!emote leaps high into the air and executes a high-kick.",
     "!emote sweep kicks at his opponent.",
     }) );
  SetCombatAction(5, ({
      "!yell NIIIIIINNNNNNJJJJJJAAAAAA!!!!!!",
      "!emote flicks his wrist in your direction.",
    }) );
  SetCombatStyleLevel("ninjitsu",50);
  SetCombatStyle("ninjitsu");
}

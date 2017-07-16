//
//  the child in the dwelling.
//  Kyla 11-2-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/13/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("child");
  SetId( ({ "child" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small child");
  SetMorality(200);
  SetRace("human");
  SetClass("fighter");
  SetLevel(2);
  SetGender("male");
  SetTown("Baria");
  SetLong(
     "This small toddler appears to be around the age of three. He "
     "plays within his home, unaware of the world around him. This "
     "innocent soul appears to be content and happy. "
  );
  SetFriends( ({"mother"}) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetAction(2, ({
     "!emote runs around the hut.",
     "!emote jumps up and down.",
     "!say Look at me mommy!",
     "!hum",
     "!smile",
     "!say When I grow up, I want to be a ranger like Alkor!",
     "!say My mommy says she loves me!",
  }) );
}


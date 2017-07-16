#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("bird");
  SetRace("bird");
  SetId( ({ "bird" }) );
  SetAdjectives( ({ "brown" }) );
  SetGender("male");
  SetShort("a brown bird");
  SetClass("animal");
  SetLevel(1);
  SetLong("The bird is a dark brown in color.  Its feet are a shade of "
	"orange and its beak is a light shade of white.  He is very "
	"small and appears to be a follower of some mage.  There is an "
	"intelligence deep in the birds eyes.");
  SetMorality(300);
  SetWander(10, ({ "go northwest", "go southwest", "go southeast", "go northeast",
	}), 1);
  SetInventory( ([ V_OBJ + "amulet" : "wear amulet" ]) );
  SetCombatAction(30, ({ 
     "!emote flutters madly about.",
     "!emote chirps out a spell.",
     "!emote attempts to look very mean.",
    }) );
  SetAction(10, ({
    "!emote flutters about.",
    "!emote sits on the edge of the catwalk.",
    "!emote sadly chirps.",
    "!say hello",
    "!emote chirps a sad song.",
   }) );
  SetDie( "Bird curses your whole family." );
}
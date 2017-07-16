#include <lib.h>
#include "../rook.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("bat");
  SetRace("bat");
  SetId( ({ "bat" }) );
  SetAdjectives( ({ "little","brown" }) );
  SetGender("male");
  SetShort("a little brown bat");
  
  SetClass("animal");
  SetLevel(1);
  SetLong("");
  SetMorality(0);
  SetCombatAction(30, ({ 
     "!emote flutters madly about.",
     "!emote squeeks very meanly!",
    }) );
  SetAction(10, ({
    "!emote flutters about.",
    "!emote perches on the ceiling.",
  }) );
  SetFriends("bat");
}

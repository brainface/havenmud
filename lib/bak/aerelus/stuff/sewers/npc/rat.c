// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include <domains.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();

  SetKeyName("skinny rat");
  SetId( ({"rat"}) );
  SetAdjectives( ({"skinny"}) );
  SetShort("a skinny rat");
  SetLong(
    "This little creature scurries around looking for food. "
    "She looks like she hasn't eaten in days. Her beady little eyes "
    "look you over as she searches for her next meal."
  );
  SetRace("rodent");
  SetClass("animal");  
  SetGender("female");
  SetLevel(3);
  SetCombatAction(3, ({
    "!emote glares at you with her beady little eyes.",
    "!emote looks for a place to hide.",
    "!emote nibbles at your ankle.",
  }) );
  SetAction(3, ({
    "!emote searches the floor for food.",
    "!emote squeaks loudly.",
  }) );  
}
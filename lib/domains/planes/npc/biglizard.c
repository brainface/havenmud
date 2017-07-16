#include <lib.h>
#include "../planes.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("lizard");
  SetId( ({ "huge lizard", "green lizard", "lizard" }) );
  SetAdjectives( ({ "huge", "green" }) );
  SetShort("a big lizard");
  SetLong("This is a huge, green lizard that lives on the Forest plane.  "
          "He has enormous, thick legs and cold scaly skin.  He walks very "
          "ponderously and slow and snorts occasionally.  He looks like he "
          "could fell a pine tree with a simple nudge.");
  
  SetRace("lizard");
  SetGender("male");
  SetClass("animal");
  SetLevel(50);
  SetWanderSpeed(10);
  SetAction(5, ({ 
    "!emote snorts."
  }) );
  }

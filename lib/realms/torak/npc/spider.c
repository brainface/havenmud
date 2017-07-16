#include <lib.h>
#include <size.h>

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("spider");
  SetId( "spider" );
  SetAdjectives( ({ "rocket" }) );
  SetShort("a rocket spider");
    SetLong(
    "This is a giant space spider with a rocket jet pack strapped to its abdomen! "
    "It is wearing a brown leather fighter pilot jacket from movies based on the 50's "
    "with matching fighter pilot goggles."
    );
    if(random(2)) { SetGender("male");
      }  else  { SetGender("female"); }
  SetRace("arachnid");
    SetClass("animal");
  SetLevel(200);
    SetRadiantLight(5);
  SetAction(15, ({
    "!emote put-puts around the room noisily on his jetpack..",
    "!emote gets stuck in a corner of the ceiling, jetpack spewing smoke everywhere..",
    "!emote careens about the room, narrowly missing you with a barrel roll!",
  }) );
}

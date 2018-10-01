//Illura@Haven
//Sept 09
#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
  SetKeyName("illura's firefly");
   SetShort("illura's firefly");
   SetId( ({ "firefly" }) );
   SetAdjectives( ({ "illura's" }) );
   SetLong("The firefly glimmers with a quiet power.");
   SetRace("insect");
   SetGender("male");
   SetClass("animal");
   SetLevel(400);
   AddLimb("left wing","torso",3,({ }) );
   AddLimb("right wing","torso",3,({ }) );
   SetAction(5, ({
    "!emote flickers.",
    "!emote dances and spirals away.",
    "!emote floats about you.",
    "!emote shines more brightly, excited by your presence.",
    "!emote circles the meadow."
  }) );
}

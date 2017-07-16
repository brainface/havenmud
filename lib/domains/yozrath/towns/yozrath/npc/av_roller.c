#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  
  SetKeyName("roller");
  SetId( ({ "roller", "bird" }) );
  SetAdjectives( ({ "small", "stocky" }) );
  SetShort("a small stocky roller");
  SetLong(
    "Small and stocky, this roller has a vibrant blue crown and vent "
    "with bright blue, turquoise and indigo wings. He gracefully dives "
    "and rolls between branches."
    );
  SetRace("bird");
  SetGender("male");
  SetClass("animal");
  SetLevel(3);
  AddLimb("torso",0,1,({ }) );
  AddLimb("head","torso",1,({ }) );
  AddLimb("left leg","torso",4,({ }) );
  AddLimb("right leg","torso",4,({ }) );
  AddLimb("left wing","torso",3,({ }) );
  AddLimb("right wing","torso",3,({ }) );
}

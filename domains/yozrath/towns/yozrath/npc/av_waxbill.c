#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  
  SetKeyName("waxbill");
  SetId( ({ "waxbill" }) );
  SetAdjectives( ({ "small", "spotted" }) );
  SetShort("a small spotted waxbill");
  SetLong(
    "Petite and sociable, this small waxbill has a red crown and vent "
    "with tiny white spots flecked across her wings. She chirps gaily "
    "and flitters around the fountain."
    );
  SetRace("bird");
  SetGender("female");
  SetClass("animal");
  SetLevel(2);
  AddLimb("torso",0,1,({ }) );
  AddLimb("head","torso",1,({ }) );
  AddLimb("left leg","torso",4,({ }) );
  AddLimb("right leg","torso",4,({ }) );
  AddLimb("left wing","torso",3,({ }) );
  AddLimb("right wing","torso",3,({ }) );
}

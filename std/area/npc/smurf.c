#include <lib.h>
inherit LIB_TRAINER;

static void create() {
	::create();
	SetKeyName("smurf");
	SetId( ({ "smurf", "trainer" }) );
	SetShort("a training smurf");
	SetAdjectives( ({ "training" }) );
	SetLong("This is a training smurf.");
  SetTrainingSkills( ({
   "stealing", "stealth",
    }) );
	SetRace("human", "smurf");
	SetGender("male");
}

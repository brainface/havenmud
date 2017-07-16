#include <lib.h>
inherit LIB_SENTIENT;

int TeachLaoise();

static void create() {
  ::create();
  SetKeyName("student");
  SetShort("a med school student");
  SetId( ({ "student", }) );
  SetAdjectives( ({ "med", "school" }) );
  SetGender("female");
  SetCommandResponses( ([
    "teach" : (: TeachLaoise :),
    ]) );
  SetLong("This is a med school student with a thing for fat guys.");
  SetRace("elf");
  SetClass("viking");
  SetLevel(42);
}

int TeachLaoise() {
	object thing;
	
	thing = present("thing", environment());
	
	if (!thing) 
	  eventForce("speak I am line #1.");
	eventForce("speak I am line #2.");
	
	if (!thing) {
		eventForce("speak I am line #3");
		eventForce("speak I am line #4");
	}
	
	return 1;
}

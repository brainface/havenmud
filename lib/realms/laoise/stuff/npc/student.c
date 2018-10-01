/* Made by Duuk to teach Laoise */

#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;

int TeachLaoise();

static void create() {
  ::create();
  SetKeyName("student");
  SetShort("a med school student");
  SetId( ({ "student", }) );
  SetAdjectives( ({ "med", "school" }) );
  SetGender("female");
  SetResistance(ALL_DAMAGE, "immune");
  SetCommandResponses( ([
    "teach" : (: TeachLaoise :),
    ]) );
  SetLong("This is a med school student with a thing for fat guys.");
  SetRace("elf");
  SetClass("viking");
  SetUndead(1);
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

#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_SENTIENT;

static void create()
{
	sentient::create();
	SetKeyName("prisoner");
	SetShort("a female elf prisoner");
	SetId(  ({ "elf", "prisoner" })  );
	SetAdjectives(  ({ "female" })  );
	SetGender("female");
	SetRace("elf");
	SetClass("fighter");
	SetSkill("knife combat");
  SetLevel(random(3) + 10);
	SetLong("This elf woman looks like she hasn't eaten in a while.  "
		"From the look of raw determination in her eyes, you can "
		"tell that she is an assassin.");
	SetAction(5,  ({ "!speak No body knows the trouble I've seen.  No "
			"body knows but Duuk!" })  );
	SetInventory(  ([ 
		P_OBJ + "spoon" : "wield spoon",
		])  );
}

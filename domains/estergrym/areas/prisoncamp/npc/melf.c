#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_SENTIENT;

static void create()
{
	sentient::create();
	SetKeyName("prisoner");
	SetShort("a male elf prisoner");
	SetId(  ({ "elf", "prisoner" })  );
	SetAdjectives(  ({ "male" })  );
	SetGender("male");
	SetRace("elf");
	SetClass("fighter");
	SetMorality(100);
  SetLevel(random(3) + 10);
  RemoveSkill("blunt combat");
	SetLong("The male prisoners are made to do all"
			" of the manual labor. "
		" He looks malnourished and scarred.");
	SetAction(5, ({ "!speak I've been working in the "
		"coal mine, moving down, down. Working in the coal "
		"mine. Whoop time to get down." })  );
	SetInventory(  ([
		P_OBJ + "sledge" : "wield sledge",
		])  );
}

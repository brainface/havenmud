#include <lib.h>
inherit "/realms/amelia/libheal.c";

static void create() {
	::create();
	SetKeyName("potion");
	SetShort("a healing potion");
	SetId( ({ "potion" }) );
	SetLong("Blerg.");
	SetHealing( ([
			"health" : 100000,
			"stamina" : 100000,
			"mana" : 100000,
			"poison" : 100000,
			"alcohol" : 100000,
			"caffeine" : 100000,
			"disease" : "oiskai flu",
		]) );
}

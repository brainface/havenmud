#include <lib.h>
#include "ginvade.h"

inherit LIB_INVADER;

static void create() {
invader::create();
SetKeyName("leader");
SetId( ({ "orc","leader" }) );
SetShort("an orc leader");
SetAdjectives("orc");
SetLong("This orc is very tall.  Standing about seven feet tall, he has to "
	"hunch down inside this tent.  His skin is brown in color and he "
	"has no hair.  He is very impressive standing there looking over "
	"maps and planning strategies.");
SetRace("orc");
SetClass("fighter");
SetAction(6, ({ "!attack first citizen","!attack first muezzin",
}) );
SetCombatAction(30, ({
	"!say Kill everything that moves!!",
	"!emote deftly moves about in an attack pattern",
	"!emote swings his sword in very skilled arcs",
}) );
SetDie("Orc leader falls down in death.");
SetInventory( ([
	GOBLIN_DIR + "leader_armour" : "wear armour",
	GOBLIN_DIR + "leader_sword" : "wield sword",
	GOBLIN_DIR + "backpack" : "wear backpack",
]) );
SetWanderSpeed(5);
SetWander(10, ({ "go south", "go up", "go south",
	}), 1);
SetLevel(20);
SetGender("male");
SetCurrency("cuicui", 25 + random(15));
}
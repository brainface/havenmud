#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_SENTIENT;

static void create()
{
	sentient::create();
	SetKeyName("taskmaster");
	SetShort("a nosferatu taskmaster");
	SetId(  ({"nosferatu", "taskmaster"})  );
	SetLong("A deathknight is always appointed to the post of "
		"taskmaster.  It is done this way first to keep the guards "
		"in and line and secondly to inspire fear in the hearts of "
		"prisoners.  This particular taskmaster seems quite "
		"competent.  The taskmaster seems much more at ease with "
		"the rod and sword than the average guard.  There also seems "
		"to be an aura of magic about the taskmaster.  ");
	SetClass("cavalier");
  SetLevel(35);
	SetClass("necromancer");
	SetMorality(-250);
	if(random(100) > 50) {
	  SetGender("male");
	}
	else {
	  SetGender("female");
	}
	SetRace("nosferatu");
	SetCurrency("bloodgems", random(80) + 100);
	SetInventory(  ([
		P_OBJ + "cloak" : "wear cloak",
	  P_OBJ + "boot"  : "wear boots",
		P_OBJ + "rod"   : "wield rod",
		P_OBJ + "sword" : "wield sword",
		])  );
	SetSpellBook(  ([
		"acid blast" : 100,
		"bone shell" : 100,
		"cloud kill" : 100,
		"wound"			 : 100,
		]) );
	SetCombatAction(50, ({
		"!cast acid blast",
		"!cast bone shell",
		"!cast cloud kill",
		"!speak DIE!",
		"!cast wound",
		})  );
  //call_out( (: eventForce, "wear first boot on right foot" :), 0);
  //call_out( (: eventForce, "wear second boot on left foot" :), 0);
}

#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_NPC;

static void create()  {
  npc::create();
  SetKeyName("guard");
  SetShort("a prison camp guard");
  SetId(  ({ "guard", "nosferatu" })  );
  SetAdjectives( ({ "prison", "guard", "camp" }) );
  SetLong(
    "This is one of the most sadistic looking Nosferatu one could "
    "ever see.  He has a maniacal grin, stroking his metal rod "
    "lovingly, and cackling whenever an elven scream pierces the air."
  );
  SetRace("nosferatu");
  SetClass("cavalier");
  SetGender("male");
  SetLevel(25);
  SetMorality(-200);
  SetCurrency("bloodgems", 100);
  SetInventory(  ([ 
  	P_OBJ + "rod"   : "wield rod",
		P_OBJ + "sword" : "wield sword",
		P_OBJ + "boot"  : "wear boots",
		])  );
}

// Coded by Zeratul
// 3-17-2000
// Mayor of Vacazar

#include <lib.h>
#include "../vacazar.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("barzurar");
  SetId( ({"barzurar","mayor"}) );
  SetAdjectives( ({ "mayor" }) );
  SetShort("Barzurar, Mayor of Vacazar");
  SetLong(
     "Barzurar is a well-built skaven with a sense of leadership. He speaks "
     "with a bold voice and rules the town in the best way he can. "
  );
  SetRace("skaven");
  SetTax(50);
  SetLocalCurrency("vacari");
  SetGender("male");
  SetClass("rogue");
  SetLevel(45);
  SetTown("Vacazar");
  SetInventory( ([
  ]) );
  SetAction(5, ({
     "!nod",
     "!speak If you wish to join the city of Vacazar, I am the one to speak to.",
     "!speak I handle the requests for citizenship.",
  }) );
  SetCombatAction(4, ({
     "!speak Fool! get away from me!",
     "!speak Get this fool off of me!",
  }) );
  }

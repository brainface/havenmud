#include <lib.h>
#include "../argoth.h"

inherit LIB_MAYOR;
static void create() {
  mayor::create();
  SetKeyName("grond");
  SetShort("Grond, Mayor of Argoth");
  SetLong(
    "After the sacking and destruction of Karak Varn, it was revealed "
    "that Grond, the former General Store owner, was responsible for betraying "
    "the town to the forces of Saahagoth.  When Argoth was built, Taigis herself "
    "decreed that Grond should lead the town.  He stands at about 7 foot tall "
    "with a proud and regal air about him."
  );
  SetLevel(45);
  SetRace("orc");
  SetClass("fighter");
  SetGender("male");
  SetTown("Karak");
  SetLocalCurrency("khuca");
  SetTax(50);
  SetInventory( ([
  ]) );
  SetAction(5, ({
    "!speak I'm the one to talk to if you want to become a citizen.",
  }) );
}

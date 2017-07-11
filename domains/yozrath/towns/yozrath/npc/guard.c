#include <lib.h>
#include "../yozrath.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("janissary");
  SetId( ({ "janissary", "guard" }) );
  SetAdjectives( ({ "emirate" }) );
  SetShort("a Janissary of the Emirate Guard");
  SetLong(
     "This tall and intimidating individual presents himself as a "
     "guard of the Emirate of Yozrath. He stands at attention, poised to "
     "strike out at the foes of the Emir. His facial expression is that "
     "of calmness and confidence in his duty. "
  );
  SetMorality(30);
  SetGender("male");
  SetRace("human");
  SetTown("Yozrath");
  SetClass("janissary");
  SetLevel(40 + random(10));
  SetInventory( ([
  ]) );
  SetCurrency( ([
  ]) );
  RemoveLanguage("Enlan");
  SetLanguage("Padashi", 100, 1);
  SetInventory( ([
    YOZRATH_OBJ "kopesh" : "wield sword",
    YOZRATH_OBJ "thobe"  : "wear thobe",
    ]) );
}


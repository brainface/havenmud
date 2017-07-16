#include <lib.h>
#include "../path.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("administrator");
  SetShort("a stodgy looking administrator");
  SetId( ({ "administrator", "glim_wander" }) );
  SetAdjectives( ({ "stodgy", "looking" }) );
  SetLong("This stodgy looking administrator handles many of the city duties "
          "in dealing with the public.  Any applications for citizenship "
          "should be addressed to him.");
  SetRace("dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(15);
  SetTown("Glimmerdin");
  SetLocalCurrency("nuggets");
  SetTax(100);
  SetMorality(100);
}

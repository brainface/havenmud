#include <lib.h>
#include "../yozrath.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("jasmin");
  SetRace("human");
  SetTown("Yozrath");
  SetBaseLanguage("Padashi");
  SetLocalCurrency("dinar");
  SetGender("female");
  SetShort("Jasmin the Musician");
  SetLong(
    "Jasmin the Musician sells the finest instruments in all of Yozrath. "
    "Her wares are used by only the best artists."
    );
  SetClass("merchant");
  SetLevel(25);
  SetMorality(250);
  SetMenuItems( ([
    "zills" : YOZRATH_OBJ "zills",
    "buzuq" : YOZRATH_OBJ "buzuq",
    "mijwiz": YOZRATH_OBJ "mijwiz",
    ]) );
  SetInventory( ([
    YOZRATH_OBJ "abaya" : "wear abaya",
    ]) );
  SetId( ({ "jasmin", "musician" }) );
  SetAdjectives( ({ "musician" }) );
  SetAction(6, ({
    "!yell Only the finest artists use Jasmin's Instruments!",
    "!yell Does your belly-dancer use Jasmin's Instruments?",
    "!yell Ask yourself: Am I good enough for a Jasmin Instrument?",
    "!speak I could sell you an instrument, but could you play it?",
  }) );
  SetLimit(1);
}

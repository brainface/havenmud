/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include <std.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("fisherman");
  SetShort("a gelfling fisherman");
  SetLong("This fisherman looks like he's a thousand years old.  "
          "His face is dark and wrinkled and his beard is long, "
          "and grey.  His ancient appearance masks the fact "
          "that he is still rather well built.");
  SetId( ({ "gelfling fisherman","fisherman","gelfling"}) );
  SetClass("rogue");
  SetClass("merchant");
  SetMorality(random(120)+400);
  SetLevel(random(5)+15);
  SetGender("male");
  SetRace("gelfling");
  SetCurrency("imperials",random(10)+80);
  SetInventory( ([
          STD_FISH + "pole" : "fish with pole",
              ]) );
  SetAction(10, ({ "!fish with pole",
                   "!speak have a seat, the fishing's fine!" }));
}


/* Approved by Duuktsaryth on Wed Sep 24 13:10:53 1997. */

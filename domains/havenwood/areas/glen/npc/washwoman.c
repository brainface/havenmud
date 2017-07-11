/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("young gelfling woman");
  SetShort("a young gelfling woman");
  SetLong("The young gelfling woman appears to be greatly over worked.  "
          "She stands here washing clothes all day and one wonders if "
          "her life has aged her well beyond her years.");
  SetId( ({ "gelfling", "young gelfling woman","gelfling woman",
            "woman","young woman" }) );
  
  SetRace("gelfling");
  SetClass("rogue");
  SetMorality(random(50)+30);
  SetLevel(random(3)+6);
  SetGender("female");
  
  SetCurrency("imperials",random(10)+20);
  SetInventory( ([
                   GLEN + "/arm/dirtysock" : "wear sock",
                   GLEN + "/arm/washedshirt" : 1,
              ]) );
  SetAction(15, ({ "The gelfling woman washes a shirt in the stream.",
                  "The woman hangs some clothes on the line." }));
}

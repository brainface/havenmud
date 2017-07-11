/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("male gelfling child");
  SetShort("a male gelfling child");
  SetLong("The male child runs around the glen screaming and chasing "
          "the other children.  His face is dirty and his clothes are "
          "ragged... yet he's still cute as can be.");
  SetId( ({ "gelfling", "child", "male" }) );
  SetAdjectives( ({ "gelfling", "male", "child" }) );
  
  SetRace("gelfling");
  SetClass("ranger");
  SetMorality(random(100)+300);
  SetLevel(random(2)+2);
  SetGender("male");
  
  SetCurrency("imperials",random(5)+5);
  SetInventory( ([
                   GLEN + "/wpn/slingshot" : "wield slingshot",
              ]) );
  SetAction(25, ({ "The child shoots a stone at a passing bird.",
                   "The child runs wildly around in circles." }));
}

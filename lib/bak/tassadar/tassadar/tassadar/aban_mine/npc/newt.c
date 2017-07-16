/* newt.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
#include "../mine.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("newt");
  SetShort("a newt");
  SetId( ({ "newt", "amphibian" }) );
  SetAdjectives( ({ "small" }) );
  SetLevel(3);
  SetRace("amphibian");
  SetClass("animal");
  SetGender("female");
  SetLong(
     "This is a small newt with thin film covering both "
     "eyes, short legs and a very short tail. The skin of "
     "the newt is a light grey color with small brown spots. "
     "She has small well worn nails, and a smooth texture."
     );
}

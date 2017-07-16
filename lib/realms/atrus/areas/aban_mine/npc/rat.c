/* rat.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
#include "../mine.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("rat");
  SetShort("a brown rat");
  SetId( ({ "rat", "rodent" }) );
  SetAdjectives( ({ "small", "brown" }) );
  SetLevel(1);
  SetRace("rodent");
  SetClass("animal");
  SetGender("male");
  SetLong(
     "This is a small brown rat with a long dirty "
     "tail and short little legs. There are "
     "large clumps of dirt and rock dust on "
     "the rat's fur. He has deep red eyes "
     "that seem to reflect back the dim "
     "light of the mine."
     );
}

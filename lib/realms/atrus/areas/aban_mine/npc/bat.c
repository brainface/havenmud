/* bat.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
#include "../mine.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("bat");
  SetShort("a small bat");
  SetId( ({ "bat", "rodent" }) );
  SetAdjectives( ({ "small", "winged" }) );
  SetLevel(1);
  SetRace("bat");
  SetClass("animal");
  SetGender("male");
  SetLong(
     "This is a small black bat with long translucent "
     "wings. Dust covers most of the bat while still "
     "allowing the color of its short fur to be seen. The "
     "claws at the end of its toes have been worn down "
     "from clinging to the ceiling of the mine."
     );
}

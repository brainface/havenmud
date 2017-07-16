//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include "../dalnairn.h"

inherit LIB_ITEM;
 
static void create() {
  ::create();
  SetShort("a calm bay");
  SetLong(
    "The calm, clear waters of the bay lap gently back "
    "and forth across the expanse allowed by the ridge "
    "arms. Waves break gently on the beach to the east. "
    "You could 'dive' into it."
  );
  SetId( ({
    "bay"
  }) );
  SetKeyName("bay");
  SetPreventGet("You get your hands wet.");
  SetInvis(2);
}

mixed direct_dive_into_obj() {
  if (this_player()->GetProperty("swimmer")) return 1;
  return 1;
}
int eventExecuteDive(object who) {
  who->eventMove(DAL_ROOM "0,0.c");
  return 1;
}

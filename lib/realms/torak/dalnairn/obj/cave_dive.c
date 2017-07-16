//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include "../dalnairn.h"

inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetShort("a cave entrance");
   SetLong(
    "An entrance to the cave in the rocky formation. "
    "You could 'dive' into it."
   );
   SetId( ({"cave"}) );
   SetKeyName("cave");
   SetPreventGet("");
  SetInvis(2);
}

mixed direct_dive_into_obj() {
  if (this_player()->GetProperty("swimmer")) return 1;
  return 1;
}
int eventExecuteDive(object who) {
  who->eventMove(DAL_ROOM "cave.c");
  return 1;
}

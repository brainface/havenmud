#include <lib.h>

inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetShort("an oasis");
   SetLong(
    "The clouds dance across the shimmering waters "
    "of this serene oasis.  The water is so deep "
    "blue its almost inviting you to dive into it."
   );
   SetId( ({"oasis"}) );
   SetKeyName("oasis");
   SetPreventGet("");
}

mixed direct_dive_into_obj() {
  if (this_player()->GetProperty("swimmer")) return 1;
  return 1;
}
int eventExecuteDive(object who) {
  who->eventMove("/realms/torak/dalnairn/room/-3,0.c");
  return 1;
}

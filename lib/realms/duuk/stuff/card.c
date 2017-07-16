#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("card");
  SetShort("a Get Out of Bjorn Free card");
  SetId( ({ "card" }) );
  SetLong(
    "This card entitles the bearer to not be held liable for Bjorn."
    "\nIt is totally not a forgery."
    );
}

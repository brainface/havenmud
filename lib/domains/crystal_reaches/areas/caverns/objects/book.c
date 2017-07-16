/*  Book the Gnome is Reading  -  Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("book");
  SetId( ({ "book" }) );
  SetShort("a book");

  SetLong("The Book has a leatherbound cover and appears to be approximately "
          "four hundred pages long.  The book looks pretty old, the pages "
          "have taken on a yellow tinge and the writing has faded slightly.");

  SetMass(50);
  SetValue(80);

  SetVendorType(VT_TREASURE);
}

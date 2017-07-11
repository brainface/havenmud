/* a skeleton
  Zara 8/17/98
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("skeleton");
  SetShort("a worthless skeleton");
  SetId( ({"skeleton"}) );
  SetAdjectives( ({"worthless"}) );
  SetLong("This skeleton is worthless.");
  SetMass(10);
  SetValue(0);
  SetVendorType(VT_TREASURE);
}

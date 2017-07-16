/* bottle
  Zara 8/14/98
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bottle");
  SetShort("a crystal perfume bottle");
  SetId( ({"bottle"}) );
  SetAdjectives( ({"carved","crystal","small"}) );
  SetLong("This small bottle is delicately carved crystal and still "
         "contains aromatic perfume.");
  SetMass(10);
  SetValue(500);
  SetVendorType(VT_TREASURE);
}

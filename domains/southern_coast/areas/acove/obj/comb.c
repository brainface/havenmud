/* comb
  Zara 8/14/98
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("comb");
  SetShort("a tortoise shell comb");
  SetId( ({"comb"}) );
  SetAdjectives( ({"tortoise","delicate","carved","shell"}) );
  SetLong("This delicate comb is intricately carved with figures "
         "of mythical animals.");
  SetMass(10);
  SetValue(200);
  SetVendorType(VT_TREASURE);
}

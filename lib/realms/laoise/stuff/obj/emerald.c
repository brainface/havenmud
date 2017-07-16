/* large emerald
  Zara 8/14/98
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("emerald");
  SetShort("a sparkling emerald");
  SetId( ({"emerald"}) );
  SetAdjectives( ({"sparkling","exquisite"}) );
  SetLong("This exquisite, sparkling emerald catches and holds "
          "the light as it enchants all those who behold it.");
  SetMass(40);
  SetValue(1000);
  SetVendorType(VT_GEM);
}

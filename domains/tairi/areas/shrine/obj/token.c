#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("token");
  SetShort("a spirit token");
  SetId( ({"token","tokens"}) );
  SetAdjectives( ({"spirit"}) );
  SetLong("This is a small coin shaped piece of"
          " wood that represents a lost soul.");
  SetMass(1);
  SetValue(200);
  SetVendorType(VT_TREASURE);
  SetDestroyOnSell(1);
}

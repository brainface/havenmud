#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("coin");
  SetShort("a ancient golden coin");
  SetId( ({ "coin"}) );
  SetAdjectives( ({"ancient","golden","gold"}) );
  SetLong("This coin dates back to a time long before"
          " the fall of Durgoroth. It is made of pure"
          " gold and has an engraving of a stoic looking"
          " bearded human on it.");
  SetMass(3);
  SetValue(600);
  SetVendorType(VT_TREASURE);
}

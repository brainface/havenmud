//
// A large floor rug
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
#include "../bazaar.h"
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("large floor rug");
   SetId( ({ "rug" }) );
   SetAdjectives( ({ "large", "floor" }) );
   SetShort("a large floor rug");
   SetLong("This exquisite hand-crafted rug would be an excellent addition "
     "to any home, building, or business. The stunning array of colors "
     "that covers this enormous rug make it a truly breathtaking piece.");
   SetMass(350);
   SetValue(150);
   SetVendorType(VT_TREASURE);
}

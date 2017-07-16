#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("large hoof");
   SetShort("a large horse hoof");
   SetId( ({ "large horse hoof","large hoof","horse hoof","hoof" }) );
   SetAdjectives( ({ "large","horse" }) );
   SetLong("The horse hoof is hard and strong, probably worth selling.");
   SetMass(5);
   SetValue(300);
   SetVendorType(VT_TREASURE);
}
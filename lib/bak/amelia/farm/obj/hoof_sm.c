#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("small hoof");
   SetShort("a small horse hoof");
   SetId( ({ "small horse hoof","small hoof","horse hoof","hoof" }) );
   SetAdjectives( ({ "small","horse" }) );
   SetLong("The horse hoof is hard and strong, probably worth selling.");
   SetMass(3);
   SetValue(150);
   SetVendorType(VT_TREASURE);
}
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sapphire lily");
   SetShort("a sapphire lily");
   SetId( ({ "sapphire","lily","sapphire lily" }) );
   SetAdjectives( ({ "pale","blue" }) );
   SetLong("This pale blue sapphire has been cut into the shape of "
           "a lily.");
   SetMass(7);
   SetVendorType(VT_GEM|VT_TREASURE);
   SetValue(110);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(50);
}

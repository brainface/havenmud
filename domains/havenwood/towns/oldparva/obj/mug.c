#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("mug");
   SetShort("an empty mug");
   SetId( ({ "mug" }) );
   SetAdjectives( ({ "empty" }) );
   SetLong("This mug is a plain brown mug that is empty.");
   SetMass(5);
   SetValue(7);
   SetDamagePoints(10);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetProperty("history","The mug came from Minkin's Inn.");
}

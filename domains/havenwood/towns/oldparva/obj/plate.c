#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("plate");
   SetShort("an empty plate");
   SetId( ({ "plate","dish" }) );
   SetAdjectives( ({ "empty" }) );
   SetLong("This plate was used to hold some meal, but now "
           "is just a dirty relic of whatever lay upon it "
           "once.  A simple blue line near the rim of the "
           "white plate is its only design.");
   SetMass(5);
   SetValue(3);
   SetDamagePoints(2);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "stone" }) );
   SetProperty("history","The plate came from Minkin's Inn.");
}

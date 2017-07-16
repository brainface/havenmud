#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("glass");
   SetShort("an empty glass");
   SetId( ({ "glass" }) );
   SetAdjectives( ({ "empty" }) );
   SetLong("This glass is a plain water glass.  It is made of "
           "a clear, durable material.");
   SetMass(3);
   SetValue(5);
   SetDamagePoints(2);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetProperty("history","The glass came from Minkin's Inn.");
}

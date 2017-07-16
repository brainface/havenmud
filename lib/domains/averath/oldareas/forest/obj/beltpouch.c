// Amelia
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_STORAGE;

static void create() {
   ::create();
   SetKeyName("belt");
   SetShort("a pouched belt");
   SetId( ({ "belt","pouch" }) );
   SetAdjectives( ({ "pouched","leather"}) );
   SetLong("A small pouch, large enough to hold a few light items, "
           "hangs off the side of this leather belt.");
   SetVendorType(VT_ARMOUR);
   SetMass(3);
   SetValue(75);
   SetDamagePoints(500);
   SetCanClose(1);
   SetClosed(0);
   SetMaxCarry(100);
   
}

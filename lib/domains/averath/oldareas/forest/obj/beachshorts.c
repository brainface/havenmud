// Amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("shorts");
   SetShort("a pair of cloth shorts");
   SetId( ({ "pair","shorts" }) );
   SetAdjectives( ({ "pair of","cloth" }) );
   SetLong(
     "The cloth shorts posses a very light tan color, and fasten with a "
     "simple drawstring. "
   );
   SetArmourType(A_PANTS);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(50);
   SetDamagePoints(150);
   SetProperty("multiples",1);
   SetSize(SIZE_MEDIUM);
}

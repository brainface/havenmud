#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("black shirt");
   SetShort("a black shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("This is a black silk shirt, which appears to have been "
           "rather well taken care of, save for the occasional tear. ");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SHIRT);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(55);
   SetValue(15);
   SetDamagePoints(250);
   SetSize(SIZE_MEDIUM);
}

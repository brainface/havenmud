#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("cloak");
   SetShort("a black cloak");
   SetId( ({ "cloak", "black cloak", }) );
   SetLong("This is a long black cloak, which appears to have been "
           "rather well taken care of, save for the occasional tear "
           "and a bit of filth at the bottom. It appears to be made "
           "out of leather, and is quite durable. ");
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetMass(125);
   SetValue(25);
   SetDamagePoints(350);
   SetSize(SIZE_MEDIUM);
}

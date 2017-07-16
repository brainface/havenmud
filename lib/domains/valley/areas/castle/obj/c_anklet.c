#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("anklet");
   SetShort("a disintegrating anklet");
   SetId( ({ "anklet","bracelet","ankle bracelet" }) );
   SetAdjectives( ({ "disintegrating","beaded" }) );
   SetLong("The cloth strands of the beaded ankle bracelet are falling "
           "apart slowly.");
   SetValue(5);
   SetMass(3);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SOCK);
   SetSize(SIZE_MEDIUM);
   SetDamagePoints(12);
   SetMaterial( ({ "textile" }) );
}


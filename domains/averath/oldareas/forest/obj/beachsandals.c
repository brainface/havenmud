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
   SetKeyName("sandals");
   SetShort("a pair of leather sandals");
   SetId( ({ "sandals","pair" }) );
   SetAdjectives( ({ "pair of","leather","brown" }) );
   SetLong(
     "Formed to protect ones' feet while leaving them open to the hot "
     "air, the sandals have a tough, inflexible bottom and two straps "
     "of adjustable leather over the top. "
   );
   SetArmourType(A_BOOT);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetSize(SIZE_MEDIUM);
   SetMass(1);
   SetValue(150);
   SetDamagePoints(450);
   SetProperty("multiples",1);
}

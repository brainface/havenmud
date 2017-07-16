// Amelia
// I'm thinking I should code some cool use function in later.
// Like, make it heal a little.  Not much though.
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("feather");
   SetShort("a bald eagle feather");
   SetId( ({ "feather" }) );
   SetAdjectives( ({ "bald","eagle" }) );
   SetLong(
     "Soft brown mini-feathers spring out of a central, "
     "hollow stalk that binds the conglomeration together. "
   );
   SetArmourType(A_HELMET);
   SetVendorType(VT_ARMOUR|VT_TREASURE);
   SetArmourClass(ARMOUR_NATURAL);
   SetMass(0.25);
   SetValue(50);
   SetDamagePoints(100);
   SetSize(SIZE_VERY_SMALL);
}

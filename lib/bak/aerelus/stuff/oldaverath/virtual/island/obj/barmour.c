#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("bone armour");
   SetShort("a suit of bone armour");
   SetId( ({ "suit of armour", "armour", }) );
   SetAdjectives( ({ "bone" }) );
   SetLong("This is a suit of armour made entirely of bones. Several "
           "of the bones have nicks and cracks on them, many of which "
           "appear to have been caused by a set of large teeth. Other "
           "than that, it actually looks like it would offer rather "
           "nice protection in combat... not to mention it looks rather "
           "intimidating. ");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BODY_ARMOUR);
   SetArmourClass(ARMOUR_NATURAL);
   SetMass(1000);
   SetValue(75);
   SetDamagePoints(750);
   SetSize(SIZE_VERY_LARGE);
}

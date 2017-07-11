//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("sash");
   SetShort("a cinnamon-colored sash");
   SetId( ({ "sash" }) );
   SetAdjectives( ({ "cinnamon", "colored" }) );
   SetLong(
    "This finely woven linen sash is dyed a rich cinnamon "
    "color. It is perhaps used to cinch the waist of a"
    "slender woman's dress.");
   SetMass(2);
   SetValue(35);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BELT);
   SetDamagePoints(100);
   SetWear("The ends of the sash swish near your ankles.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(1);
}

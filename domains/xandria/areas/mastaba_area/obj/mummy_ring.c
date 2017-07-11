//Selket@Haven
//2006
#include <size.h>
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("ring");
   SetShort("a heavy ring of electrum");
   SetId( ({ "ring","band","electrum" }) );
   SetAdjectives( ({ "electrum", "heavy" }) );
   SetLong("This is a very substantial ring fashioned from electrum, "
           "a naturally occuring substance of gold and silver. It "
           "is inlaid with carnelian and lapis lazuli in the pattern "
           "of little lotuses, and seems to be very weighty in the hand.");
   SetMass(4);
  SetValue(300);
   SetDamagePoints(900);
   SetArmourType(A_RING);
  SetArmourClass(ARMOUR_CHAIN);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   SetMaterial( ({ "metal" }) );
   SetSize(SIZE_MEDIUM);
}

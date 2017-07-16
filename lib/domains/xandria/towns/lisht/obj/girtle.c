//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("girtle");
   SetShort("an embroidered girtle");
   SetId( ({ "girtle" }) );
   SetAdjectives( ({ "embroidered" }) );
  SetLong(
    "The girtle is rather large, but beautifully embroidered "
    "in many stunningly dyed threads. It wraps around one's "
    "waist like a sash, and offers very slight protection. "
  );
   SetMass(3);
   SetValue(50);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BELT);
   SetDamagePoints(500);
   SetProperty("magic","The girtle seems to protect the "
               "wearer slightly.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(2);
   SetSize(SIZE_MEDIUM);
}

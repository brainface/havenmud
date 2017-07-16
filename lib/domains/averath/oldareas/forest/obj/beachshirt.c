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
   SetKeyName("shirt");
   SetShort("a light tan shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "light","tan" }) );
   SetLong(
     "The thick cloth shirt buttons up the front, and has long "
     "sleeves of the same "
     "light tan color as the rest of the article of clothing. "
   );
   SetArmourType(A_SHIRT);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(50);
   SetDamagePoints(150);
   SetSize(SIZE_MEDIUM);
}


#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("shield");
   SetId( ({ "shield" }) );
   SetAdjectives( ({ "battered" }) );
   SetShort("a battered shield");
   SetLong(
   "Round in shape this particular piece of armour is warped and has been "
   "crafted poorly. The surface on the outside of the shield has a light "
   "blue color painted on it, with chips and scrapings amoung the edges. "
   "The inside has one leather strap for the wearer to grasp and hold "
   "properly. The inside shows some bends and dents that make this "
   "shield warped but still holds the round quality it was intended."
   );
   SetVendorType(VT_ARMOUR);
   SetMass(75);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_PLATE);
   SetValue(60);
   SetDamagePoints(150);
   SetMaterial( ({ "metal" }) );
   SetArmourType(A_SHIELD);
   SetRepairDifficulty(3);
   SetProtectionBonus(BLUNT, -1);
}

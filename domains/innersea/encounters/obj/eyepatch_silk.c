#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("elegant eyepatch");
  SetId( ({ "eyepatch" }) );
  SetAdjectives( ({ "elegant" }) );
  SetShort("an elegant eyepatch");
  SetLong(
    "This eyepatch is sewn from the finest black silk and "
    "allows one to hide an empty eyesocket in style."
  );
  SetMass(20);
  SetValue(2000);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(1000);
  SetArmourType(A_VISOR);
  SetVendorType(VT_TREASURE | VT_CLOTHING);
  SetMaterial( ({ "textile" }) );
  SetWarmth(0);
  SetWear("You feel much more dashing if not a little squinty.");
  SetProperty("history",
     "Long, long ago there was a charming young Prince who was mercilessly... "
     "No really, it's just an eyepatch, no need to get all sentimental about it."
     );
  SetRepairDifficulty(20);
}

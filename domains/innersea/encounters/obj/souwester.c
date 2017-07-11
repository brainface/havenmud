// mahkefel 20101203
// saily jacket
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("souwester");
  SetId( ({ "souwester","raincoat", "coat" }) );
  SetAdjectives( ({ "rain","yellow" }) );
  SetShort("a yellow souwester");
  SetLong(
    "This heavy yellow raincoat is made from slick oil cloth. "
    "Made to keep a sailor dry during heavy rains from a "
    "sou'wester gale, it would do little to stop a knife or sword."
  );
  SetMass(200);
  SetValue(1000);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetMaterial( ({"textile" }) );
  SetWarmth(20);
  SetRepairDifficulty(20);
}


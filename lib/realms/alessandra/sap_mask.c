#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("elven mask");
  SetId( ({ "mask" }) );
  SetAdjectives( ({ "painted","elven","wooden" }) );
  SetShort("a painted elven mask");
  SetLong(
    "A carictured drawing of a widely grinning elven woman's face adorns "
    "this mask in gaudy colors. Rose red splotches give a blushing appearance "
    "and large holes left open for the eyes are marked with dark eyelashes. "
    "Something red stains the somewhat rough opening for the mouth, and doesn't "
    "quite look like lipstick."
  );
  SetMass(150);
  SetValue(250);
  SetMaterial( ({ "wood" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetWarmth(5);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_HELMET);
  SetSize(SIZE_LARGE);
  SetDamagePoints(2500);
}


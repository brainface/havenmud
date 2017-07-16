// Torak jan 2012 taken directly from ninja_tower //
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("tail wrap");
  SetShort("a cloth tail wrap");
  SetId( ({ "wrap" }) );
  SetAdjectives( ({ "cloth", "tail" }) );
  SetLong("This cloth tail wrap is laced with string and "
    "when worn around the tail is tied together for a nice "
    "fit.");
  SetValue(200);
  SetMass(20);
  SetSize(SIZE_MEDIUM);
  SetWarmth(2);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_TAIL);
  SetRestrictLimbs( ({ "tail" }) );
  SetDamagePoints(450);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(15);
}

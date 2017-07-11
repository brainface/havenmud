//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("bronze armour");
  SetId( ({ "armour"}) );
  SetAdjectives( ({ "bronze" }) );
  SetShort("bronze armour");
  SetLong(
    "This armour is made of little links of bronze "
    "and lashed to the body with strips of leather.");
  SetMaterial( ({ "metal", "leather" }) );
  SetWarmth(4);
  SetArmourClass(ARMOUR_CHAIN);
  SetVendorType(VT_ARMOUR);
  SetMass(140);
  SetValue(300);
  SetDamagePoints(1000);
  SetArmourType(A_ARMOUR);
  SetRestrictLimbs( ({ "right arm", "left arm", "torso"}) );
}

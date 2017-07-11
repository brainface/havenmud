#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "old", "leather" }) );
  SetShort("a pair of old leather boots");
  SetLong(
    "This old boot is made from inferior leather, and is barely held together "
    "by rusty metal studs. It seems rather ineffective at providing much "
    "protection, and has obviously been worn to battle a great many times. "       
  );
  SetMass(80);
  SetMaterial( ({ "leather" }) );
  SetValue(0);
  SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetSize(SIZE_SMALL);
  SetDamagePoints(800);
}

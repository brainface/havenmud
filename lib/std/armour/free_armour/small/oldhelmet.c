#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather helmet");
  SetId( ({ "helmet" }) );
  SetAdjectives( ({ "old", "leather" }) );
  SetShort("an old leather helmet");
  SetLong(
    "This old helmet is made from inferior leather, and is barely held together "
    "by rusty metal studs. It seems rather ineffective at providing much "
    "protection, and has obviously been worn to battle a great many times. "     
  );
  SetMass(75);
  SetValue(0);
  SetMaterial( ({ "leather" }) );
  SetArmourClass(ARMOUR_LEATHER);   
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_HELMET);
  SetSize(SIZE_SMALL);
  SetDamagePoints(800);
}

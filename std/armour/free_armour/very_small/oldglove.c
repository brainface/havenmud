#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather glove");
  SetId( ({ "glove" }) );
  SetAdjectives( ({ "old", "leather" }) );
  SetShort("an old leather glove");
  SetLong(
    "This old glove is made from inferior leather, and is barely held together "
    "by rusty metal studs. It seems rather ineffective at providing much "
    "protection, and has obviously been worn to battle a great many times. "    
  );
  SetMass(5);
  SetValue(0);
  SetMaterial( ({ "leather" }) );
  SetArmourClass(ARMOUR_LEATHER);   
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_GLOVE);
  SetSize(SIZE_VERY_SMALL);
  SetDamagePoints(800);
}

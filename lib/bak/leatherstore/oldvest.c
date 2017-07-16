#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather vest");
  SetId( ({ "vest" }) );
  SetAdjectives( ({ "old", "leather" }) );
  SetShort("an old leather vest");
  SetLong(
    "This old vest is made from inferior leather, and is barely held together "
    "by rusty metal studs. It seems rather ineffective at providing much "
    "protection, and has obviously been worn to battle a great many times. "    
  );
  SetMass(175);
  SetMaterial( ({ "leather" }) );
  SetValue(0);  
  SetArmourClass(ARMOUR_LEATHER);  
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  SetSize(SIZE_LARGE);
  SetDamagePoints(800);
}

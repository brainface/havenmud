#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("leather pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "a", "pair", "of", "old", "leather" }) );
  SetShort("a pair of old leather pants");
  SetLong(
    "This pair of pants is made from inferior leather, and are barely held together "
    "by rusty metal studs. They seem rather ineffective at providing much "
    "protection, and have obviously been worn to battle a great many times. "    
  );
  SetMass(160);
  SetMaterial( ({ "leather" }) );
  SetValue(0);
  SetProperty("multiples", 1);  
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(800);
}

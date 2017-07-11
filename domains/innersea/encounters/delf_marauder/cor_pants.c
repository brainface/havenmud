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
  SetAdjectives( ({ "pair of", "laced", "leather", "black" }) );
  SetShort("a pair of laced leather pants");
  SetLong(
     "These black leather pants are very tight, clinging to every curve "
     "like a second skin. Blood red leather string criss-crosses up "
     "the side of each leg and ties at the sides of the waist. The leather "
     "itself is quite finely made, durability and fashion at its finest."
     );
  SetMass(150);
  SetWarmth(5);
  SetValue(500);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}

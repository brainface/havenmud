//  ratty pants for a skaven scalawag
//  *giggle*

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "ratty", "dirty", "shabby", "tattered" }) );
  SetShort("a pair of ratty pants");
  SetLong(
     "This pair of ratty pants were probably once white, or at least "
     "tan, but now are a dirty greyish-brown. The waist is cinched "
     "with what is probably a rigging rope tied in knots around it and "
     "the pant legs are shabby and tattered. It would be fair to say "
     "these pants have seen better days."
     );
  SetMass(40);
  SetWarmth(2);
  SetValue(10);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH); 
  SetVendorType(VT_CLOTHING);
  SetMaterial( ({ "textile" }) );
  SetDamagePoints(1500);
  SetRepairDifficulty(15);
  
}

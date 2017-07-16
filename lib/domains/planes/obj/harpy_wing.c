/*                                                                                                                                           
 * A leather wingguard for harpies                                                                                                      
 *                                                                                                                                           
 *                                                                                                                                           
 */                                                                                                                                          
#include <lib.h>                                                                                                                             
#include <vendor_types.h>                                                                                                                    
#include <size.h>                                                                                                                            
#include <armour_class.h>                                                                                                                    
#include <armour_types.h>                                                                                                                    

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("feathered hide");
  SetId(( {"hide"} ));
  SetShort("a feathered hide");
  SetAdjectives( ({"feathered"}) );
  SetLong(
    "This seems to be nothing less than a skinned hide from the "
    "wing of some creature. Long, black feathers with white "
    "markings at the tips cover the skin, and a few holes are left "
    "from whatever wounds felled it. Cleaned up, it might be some worth "
    "to a merchant; or the coarse hide could be worn for protection, if you "
    "had somewhere wing-shaped to wear it."
  );
  SetArmourType(A_WING);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(2000);
  SetMass(200);
  SetMaterial("leather");
  SetRepairDifficulty(50);
  SetSize(SIZE_LARGE);
  SetValue(1000);
  SetVendorType(VT_ARMOUR);
  SetWarmth(15);
  SetWear("Your wings are comfortably warmed by the macabre garment.");
}



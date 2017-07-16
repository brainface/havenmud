//  Fancy Gown for Clothier
//  Desc by Vaash - Alessandra 2009

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  
  SetKeyName("gown");
  SetShort("an elegant satin gown");
  SetId( ({"gown"}) );
  SetAdjectives( ({"satin", "elegant"}) );
  SetLong(
     "A beautiful satin rose in color, this elegant gown is hand sewn and "
     "beaded. The bodice is fit and tapers into a point, with the skirt "
     "gracefully flowing to the ground. A sheer rose colored material forms "
     "small cap sleeves from the bodice."            
     );
  SetMass(60);
  SetWarmth(12);
  SetSize(SIZE_MEDIUM);
  SetValue(2500);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetDamagePoints(700);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_BODY_ARMOUR);

}

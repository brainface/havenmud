//   For Swashbuckling trainer
//   Aless 2011

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("feathered hat");
  SetId( ({ "hat" }) );
  SetAdjectives( ({ "velvet", "blue", "feathered" }) );
  SetShort("a finely feathered hat");
  SetLong(
     "A distinguished shade of deep blue velvet, this hat has " 
     "obviously been commissioned by a fashionable member of "
     "the debonair set. Its wide brim brandishes a large, brilliant "
     "white plumage to rival that of any self respecting fowl."
     );
  SetMass(50);
  SetWarmth(2);
  SetValue(1000);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "textile" }) );
  SetDamagePoints(2000);
  SetRepairDifficulty(20);
  
}

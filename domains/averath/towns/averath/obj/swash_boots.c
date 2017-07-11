//   Fancy boots for swashbucklers
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
  
  SetKeyName("leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "leather", "cuffed", "brown", "dark brown" }) );
  SetShort("cuffed leather boots");
  SetLong(
     "The top of these knee boots fold over forming a wide cuff. "
     "The dark brown leather is stitched with precision making "
     "these boots an essential for the fashionable few." 
     );
  SetMass(80);
  SetWarmth(5);
  SetValue(350);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BOOT);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}

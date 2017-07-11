// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("overalls");
  SetId( ({ "overalls" }) );
  SetAdjectives( ({ "pair", "of" , "dusty" }) );
  SetShort("a pair of dusty overalls");
  SetLong(
     "This dusty pair of overalls look to be the clothing of the average farmer. The "
     "location around the knee area of the leg sleeves look to have been worn heavily, while "
     "the edges of each opening is frayed and torn. Dust completely covers this pair "
     "of overalls, keeping them looking even worse off than if they where clean. "
     );
  SetMass(150);
  SetWarmth(3);
  SetVendorType(VT_CLOTHING);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_PANTS);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_MEDIUM);
}

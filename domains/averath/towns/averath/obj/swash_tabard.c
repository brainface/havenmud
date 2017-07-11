//   swashbuckler fancy clothes
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
  
  SetKeyName("shirt");
  SetId( ({ "shirt", "tabard" }) );
  SetAdjectives( ({ "fancy", "white", "silk", "blue", "velvet" }) );
  SetShort("a fancy shirt and tabard");
  SetLong(
     "The tabard falls to the waist in all of its deep blue velvet splendor. "
     "White embroidery on the chest marks the crest of a rather "
     "selective few who are greatly skilled in the finer arts of fencing. "
     "Long, billowing white sleeves of the finest silk peek from the "
     "loose arms of the tabard and a white lace jabot adorns the neck. "
     );
  SetWear( "Surely, all of your peers will be envious of your dapper stylings." );
  SetMass(50);
  SetWarmth(4);
  SetValue(1000);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH); 
  SetVendorType(VT_CLOTHING);
  SetMaterial( ({ "textile" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}

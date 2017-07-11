//  Fancy Pants for Clothier
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
  
  SetKeyName("pants");
  SetShort("a pair of fitted dark leather pants");
  SetId( ({"pants"}) );
  SetAdjectives( ({"fitted", "dark", "leather"}) );
  SetLong(
     "Crafted of a buttery soft leather and dyed to a dark brown, these "
     "pants are finely tailored for a close fit. Free of adornments, "
     "this high quality garment would likely provide reasonable protection "
     "in addition to nicely completing any outfit."         
     );
  SetMass(35);
  SetWarmth(12);
  SetSize(SIZE_MEDIUM);
  SetValue(1500);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetDamagePoints(1000);
  SetMaterial("leather");
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_PANTS);

}

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("linen pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "a", "pair", "of", "old", "cloth" }) );
  SetShort("a pair of old cloth pants");
  SetLong(
    "These old pants are made from a light weight linen which offers very little "
    "warmth and protection. The pants could very well be a hand-me-down from a "
    "distant relative with how they are covered in various yellowish stains. "    
    );
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetValue(2000);
  SetWarmth(2);
  SetProperty("multiples", 1);  
  SetArmourClass(ARMOUR_CLOTH); 
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  SetRepairDifficulty(70);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(1000);
}

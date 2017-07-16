#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() 
{
  armour::create();
  SetKeyName("sandals");
  SetId( ({ "sandals", "leather sandals" }) );
  SetAdjectives( ({ "comfortable", "practical" }) );
  SetShort("leather sandals");
  SetLong("These sandals look comfortable and practical.");
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetMass(50);
  SetValue(35);
  SetDamagePoints(25);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(SLASH, 2);
  // SetProtection(COLD,2);
  SetArmourType(A_BOOT);
  SetArmourClass(ARMOUR_LEATHER);
  SetMaterial( ({"leather"}) );
  SetProperty("multiples", 1);
  SetWarmth(2);
  SetRepairSkills( ([
                     "leather working" : 1,
                     "armour smithing" : 2,
                 ]) );
  SetRepairDifficulty(5);
}

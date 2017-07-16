#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() 
{
  armour::create();
  SetKeyName("polished leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "leather", "polished","comfortable","attractive","thick" }) );
  SetShort("leather boots");
  SetLong("These polished leather boots look quite comfortable and "
          "highly attractive. Thick leather protects from the discomfort "
          "of travel on foot quite effectively.");
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetValue(80);
  SetDamagePoints(65);
  SetArmourClass(ARMOUR_LEATHER);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(SLASH, 2);
  // SetProtection(COLD,2);
  SetArmourType(A_BOOT);
  SetMaterial( ({"leather"}) );
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetRepairSkills( ([
                     "leather working" : 3,
                     "armour smithing" : 3,
                 ]) );
  SetRepairDifficulty(10);
}


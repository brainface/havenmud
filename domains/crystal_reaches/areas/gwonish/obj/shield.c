
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("banded shield");
  SetId(({"shield", "banded shield","wooden shield", 
            "banded wooden shield" }));
  SetShort("a banded wooden shield");
  SetLong( "Iron bands the round wooden shield." );
  SetMaterial( ({"wood","metal"}) );
  SetWarmth(0);
  SetRepairSkills( ([
                     "wood working" : 1,
                     "metal working" : 2,
                     "armour smithing" : 2
                 ]) );
  SetRepairDifficulty(12);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints((300+(random(3)*100)));
  SetVendorType(VT_ARMOUR);
  SetMass(200);
  SetValue(100);
  SetArmourType(A_SHIELD);
  
  // SetProtection(BLUNT,3);
  // SetProtection(SLASH,3);
  // SetProtection(PIERCE,5);
  // SetProtection(ACID,3);
}

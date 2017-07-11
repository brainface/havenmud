
#include <lib.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("chainmail vest");
  SetId(( { "chainmail", "vest","chainmail vest", 
            "chain","chain vest" }));
  SetShort("a chainmail vest");
  SetLong("The rings of the chainmail vest are of an extremely large gauge.");
  SetMaterial( ({"metal"}) );
  SetWarmth(0);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_MEDIUM);
  SetRepairSkills( ([
                     "metal working" : 2,
                     "armour smithing" : 2
                 ]) );
  SetRepairDifficulty(10);
  SetDamagePoints((450+(random(3)*100)));
  SetVendorType(VT_ARMOUR);
  SetMass(400);
  SetValue(400);
  SetArmourType(A_ARMOUR);
  
  // SetProtection(BLUNT,1);
  // SetProtection(SLASH,5);
  // SetProtection(PIERCE,4);
}

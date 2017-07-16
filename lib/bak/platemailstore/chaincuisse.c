#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cuisse");
  SetId(( {"cuisse"} ));
  SetShort("a large chainmail cuisse");
  SetAdjectives( ({"large", "chainmail"}) );  
  SetLong(
    "This sturdy cuisse is crafted of small chain links. The cuisse covers "
    "most of the legs, leaving "
    "very little exposed to danger when combined with other pieces. It is lined "
    "with fine linen, providing comfort to the wearer aswell as superiour "
    "protection."    
  );   
  SetMass(400);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_LARGE);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_PANTS);  
  SetWear("The chainmail cuisse feels very comfortable.");
}
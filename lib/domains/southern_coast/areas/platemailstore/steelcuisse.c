#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("steel cuisse");
  SetId(( {"cuisse"} ));
  SetShort("a steel cuisse");
  SetAdjectives( ({"steel"}) );  
  SetLong(
    "This sturdy cuisse is crafted of tough steel. The plate covering "
    "the left leg of the wearer has a small carving of an anvil, "
    "signifying that this suit was crafted by Kelan, perhaps the finest smith "
    "in the Southern Coast region. The cuisse covers most of the legs, leaving "
    "very little exposed to danger when combined with other pieces. It is lined "
    "with fine silk, providing comfort to the wearer aswell as superiour "
    "protection."    
  );   
  SetMass(400);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_PANTS);  
  SetWear("The steel cuisse feels very comfortable.");
}
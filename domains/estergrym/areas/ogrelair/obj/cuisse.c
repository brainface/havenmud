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
  SetShort("a steel ogre-sized cuisse");
  SetAdjectives( ({"steel", "ogre-sized"}) );  
  SetLong(
    "This sturdy cuisse is crafted of tough steel. The cuisse covers most of "
    "the legs, leaving very little exposed to danger when combined with other "
    "pieces. It is lined with soft fur, providing added comfort."
  );   
  SetMass(400);
  SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_LARGE);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_PANTS);  
  SetWear("The steel cuisse feels very comfortable.");
}

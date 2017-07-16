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
  SetShort("a small steel cuisse");
  SetAdjectives( ({"small", "steel", }) );  
  SetLong(
    "This sturdy cuisse is crafted of tough steel. The cuisse covers most "
    "of the legs, leaving very little exposed to danger when combined with other "
    "pieces. It is lined with fine silk, providing comfort to the wearer as "
    "well as superiour protection."    
  );   
  SetMass(400);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_PANTS);  
  SetWear("The steel cuisse feels very comfortable.");
}
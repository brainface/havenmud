#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("steel breastplate");
  SetId(( {"breastplate"} ));
  SetShort("a small black steel breastplate");
  SetAdjectives( ({"steel", "small"}) );  
  SetLong(
    "This sturdy breastplate is crafted of tough black steel. It covers "
    "most of the wearer's torso, leaving little room for weapons to cause "
    "harm. The breastplate appears to offer great protection, though seems "
    "rather cumbersome. It is lined with black silk to provide comfort and "
    "warmth."    
  );   
  SetMass(350);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(2);
  SetRepairDifficulty(70);
  SetValue(5000);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);  
  SetWear("The black steel breastplate feels very comfortable.");
}
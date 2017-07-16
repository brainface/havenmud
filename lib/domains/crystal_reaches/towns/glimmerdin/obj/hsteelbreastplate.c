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
  SetShort("a small heavy steel breastplate");
  SetAdjectives( ({"small", "steel", "heavy"}) );  
  SetLong(
    "This sturdy breastplate is crafted of tough steel. It covers most of the "
    "wearer's torso, leaving little room for weapons to cause harm. The "
    "breastplate appears to offer great protection, though seems rather "
    "cumbersome. It is lined with silk to provide comfort and warmth."    
  );   
  SetMass(500);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);  
  SetWear("The steel breastplate feels very comfortable.");
}
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("vest");
  SetId(( {"vest"} ));
  SetShort("a small black chainmail vest");
  SetAdjectives( ({"chainmail", "small"}) );  
  SetLong(
    "This sturdy vest is crafted of small black chain links. It covers "
    "most of the wearer's torso, leaving little room for weapons to "
    "cause harm. The vest appears to offer great protection, though "
    "seems rather cumbersome. It is lined with fine black linen to "
    "provide comfort."    
  );   
  SetMass(350);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);  
  SetWear("The black chainmail vest feels very comfortable.");
}
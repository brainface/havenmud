#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("gauntlet");
  SetId(( {"gauntlet" } ));
  SetShort("a silver gauntlet");
  SetAdjectives( ({"silver"}) );
  SetLong(
    "This gauntlet is crafted of steel and well-polished to look like silver. "
    "It offers superb protection to the wearer's hand, while allowing adequate "
    "maneuverability. The gauntlet is lined with soft fur, providing a little "
    "warmth, making the piece of armour rather comfortable." );     
  SetMass(35);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("metal");
  SetWarmth(1);
  SetRepairDifficulty(70);
  SetValue(1500);
  SetDamagePoints(1000);
  SetArmourType(A_GLOVE);  
}
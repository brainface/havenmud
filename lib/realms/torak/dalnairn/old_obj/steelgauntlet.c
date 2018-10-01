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
  SetShort("a small black chainmail gauntlet");
  SetAdjectives( ({"small","chainmail", "black"}) );
  SetLong(
    "This gauntlet is crafted of tough black steel. It offers superb protection "
    "to the wearer's hand, while allowing adequate maneuverability. The "
    "gauntlet is lined with fine black silk, providing a little warmth, making "
    "the piece of armour rather comfortable."    
  );     
  SetMass(250);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(2);
  SetRepairDifficulty(70);
  SetValue(1500);
  SetDamagePoints(25000);
  SetArmourType(A_GLOVE);  
  SetWear("The black steel gauntlet feels very comfortable.");
}
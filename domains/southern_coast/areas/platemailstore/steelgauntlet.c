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
  SetShort("a steel gauntlet");
  SetAdjectives( ({"steel"}) );
  SetLong(
    "This gauntlet is crafted of tough steel. It offers superb protection "
    "to the wearer's hand, while allowing adequate maneuverability. The "
    "gauntlet is lined with fine silk, providing a little warmth, making "
    "the piece of armour rather comfortable."    
  );     
  SetMass(250);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(1500);
  SetDamagePoints(25000);
  SetArmourType(A_GLOVE);  
  SetWear("The steel gauntlet feels very comfortable.");
}
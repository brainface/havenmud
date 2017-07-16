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
  SetShort("a black chainmail gauntlet");
  SetAdjectives( ({"","chainmail", "black"}) );
  SetLong(
    "This gauntlet is crafted of small black chain links. It offers superb "
    "protection to the wearer's hand, while allowing adequate maneuverability. "
    "The gauntlet is lined with fine black linen, making the piece of armour "
    "rather comfortable."    
  );     
  SetMass(250);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(2500);
  SetDamagePoints(25000);
  SetArmourType(A_GLOVE);  
  SetWear("The black chainmail gauntlet feels very comfortable.");
}
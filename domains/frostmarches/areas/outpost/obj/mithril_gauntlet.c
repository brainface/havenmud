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
  SetShort("a mithril gauntlet");
  SetAdjectives( ({"silver"}) );
  SetLong(
    "This gauntlet is crafted of mithril. It offers superb protection "
    "to the wearer's hand, while allowing adequate maneuverability. The "
    "gauntlet is lined with soft fur, providing a little warmth, making "
    "the piece of armour rather comfortable." );     
  SetMass(35);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(12500);
  SetDamagePoints(2000);
  SetArmourType(A_GLOVE);  
}
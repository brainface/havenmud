#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId(( {"boots" } ));
  SetShort("a pair of small heavy black steel boots");
  SetAdjectives( ({"small", "steel", "pair of", "black"}) );
  SetLong(
    "These sturdy boots are crafted of tough black steel. The boots "
    "entirely cover the wearer's feet, leaving little exposed to danger "
    "when combined with similar pieces. They are lined with fine black "
    "silk, providing comfort to the wearer aswell as superiour protection."
  );   
  SetProperty("multiples", 1);
  SetMass(200);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(2);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(25000);
  SetArmourType(A_BOOT);  
  SetWear("The black steel boots feel very comfortable.");
}
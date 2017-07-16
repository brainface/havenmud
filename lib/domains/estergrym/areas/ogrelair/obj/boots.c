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
  SetShort("a pair of steel ogre-sized boots");
  SetAdjectives( ({"steel", "pair of", "ogre-sized"}) );
  SetLong(
    "These sturdy boots are crafted of tough steel. "
    "The boots entirely cover the wearer's feet, leaving "
    "little exposed to danger when combined with similar pieces. They "
    "are lined with soft fur, providing some added comfort. There is a "
    "small, crudely engraved symbol on the left boot."
  );   
  SetProperty("multiples", 1);
  SetMass(150);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_LARGE);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(3000);
  SetDamagePoints(2500);
  SetArmourType(A_BOOT);  
  SetWear("The steel boots feel very comfortable.");
}

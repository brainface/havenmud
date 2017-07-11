/*
 A chainmail pants for scions
*/
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cuisse");
  SetId(( {"cuisse"} ));
  SetShort("a golden chainmail cuisse");
  SetAdjectives( ({"chainmail", "golden"}) );  
  SetLong(
    "This gleaming cuisse made of links of some golden alloy. Solid plates "
    "provide additional protection for the thighs and knees, and silk "
    "underlining pads the interior."
  );   
  SetArmourType(A_PANTS);  
  SetArmourClass(ARMOUR_CHAIN);
  SetDamagePoints(6000);
  SetMass(250);
  SetMaterial("metal");
  SetProperty("history",
    "This armour is a type worn by scions, a being of pure "
    "good found on the upper planes. It is gifted to those "
    "of their number who have served Duuk through trials "
    "of combat against the forces of chaos."
  );
  SetRepairDifficulty(90);
  SetSize(SIZE_MEDIUM);
  SetValue(6000);
  SetVendorType(VT_ARMOUR);
  SetWarmth(0);
  SetWear("The chainmail cuisse feels unusually light for its size.");
}


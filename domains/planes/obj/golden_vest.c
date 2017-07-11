/*
 A chainmail vest for scions
*/
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
  SetShort("a golden chainmail vest");
  SetAdjectives( ({"chainmail", "golden"}) );  
  SetLong(
    "This shining vest is made of links of a golden metal. It flows over "
    "the chest and arms of the wearer, providing great protection against "
    "cuts and blows. A white silk undershirt allows some comfort to the "
    "wearer."
  );   
  SetArmourType(A_ARMOUR);  
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
  SetWear("The chainmail vest feels unusually light for its size.");
}


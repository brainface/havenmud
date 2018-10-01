//   Ewok reinforced armour   //

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("tunic");
  SetId( ({ "tunic" }) );
  SetAdjectives( ({ "dark", "studded", "leather" }) );
  SetMaterials( ({ "leather" }) );
  SetRepairDifficulty(15);
  SetShort("a studded leather tunic");
  SetLong("Iron studs ring the neckline of this dark leather tunic. "
     "Reinforced with an extra layer of hardened leather, this offers "
     "slightly more protection than your average leather tunic. ");
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_SMALL);
  SetMass(40);
  SetWarmth(15);
  SetValue(125);
  SetDamagePoints(450);
  SetArmourType(A_SHIRT);
}

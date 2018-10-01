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
  SetKeyName("glove");
  SetId( ({ "glove", "leather glove" }) );
  SetAdjectives( ({ "studded", "leather", "toughened" }) );
  SetMaterials( ({ "leather" }) );
  SetRepairDifficulty(15);
  SetShort("a studded leather glove");
  SetLong("Small iron studs decorate the wrists of these toughened "
     "leather gloves. The leather has been reinforced to provide more "
     "protection without dulling movement.");
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_SMALL);
  SetMass(15);
  SetWarmth(5);
  SetValue(45);
  SetDamagePoints(350);
  SetArmourType(A_GLOVE);
}

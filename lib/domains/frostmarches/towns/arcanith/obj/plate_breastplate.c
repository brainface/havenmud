#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breastplate");
  SetId(( {"breastplate"} ));
  SetShort("a salvaged steel breastplate");
  SetAdjectives( ({"steel", "salvaged"}) );
  SetLong(
    "This ancient breastplate looks like it was salvaged from some ruined "
    "armoury. Once polished steel is dull with age, though it shows no signs "
    "of rust. Elegant sigils cover the rigid plates on the chest and "
    "pauldrons, and obviously refurbished chainmail shields the wearer's "
    "joints."
  );
  SetMass(250);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);
  SetWear("The breastplate's sigils flicker faintly with a blue light, "
    "then fade.");
}


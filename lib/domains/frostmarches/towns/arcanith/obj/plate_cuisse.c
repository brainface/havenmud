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
  SetShort("a salvaged steel cuisse");
  SetAdjectives( ({"steel", "salvaged"}) );
  SetLong(
    "These ancient steel leggings are dulled with age. A recently made seam "
    "running along the rear of the legs show where it has been reduced in "
    "size to fit a smaller form. Faded sigils adorn the knees and thighs. "
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
  SetArmourType(A_PANTS);
  SetWear("The cuisse's sigils flicker faintly with a blue light, "
    "then fade.");
}

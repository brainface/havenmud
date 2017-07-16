#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetId(( {"shirt"} ));
  SetShort("a boarhide shirt");
  SetAdjectives( ({"boarhide",}) );
  SetLong(
    "This shirt is sewn from thick boarhide. It covers the chest and upper arms, "
    "and hangs down a little below the waist. The shoulders are attached with "
    "thinner cloth to allow some flexibility, while the chest and arms are padded "
    "with hide thick enough to stop a bear's teeth, for a moment, at least."
  );
  SetMass(350);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);
  SetWear("The boarskin shirt feels a little scratchy.");
}

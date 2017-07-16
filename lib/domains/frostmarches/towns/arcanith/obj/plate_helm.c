#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helm");
  SetId(( {"helm"} ));
  SetShort("a salvaged steel helm");
  SetAdjectives( ({"steel", "salvaged"}) );
  SetLong(
    "This open-faced helm would cover the head with a thick layer "
    "of ancient steel. Some work has obviously been spent in restoring "
    "the helmet to its former glory, as newly harvested horsehair sprays "
    "from the plume at the crest of the helmet."
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
  SetArmourType(A_HELMET);
  SetWear("Horsehair falls to the floor around you as you don the helmet.");
}

#include <lib.h>     
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leggings");
  SetId(( {"leggings"} ));
  SetShort("a pair of boarhide leggings");
  SetAdjectives( ({"boarhide", "pair of" }) );
  SetLong(
    "These leggings are sewn from thick boarhide. They cover the groin and legs "
    "of the wearer, padded with thick enough leather to stop the fangs of all "
    "but the largest viper."
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
  SetArmourType(A_PANTS);
  SetWear("The thick hide leggings feel a little scratchy.");
}



#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boarskin glove");
  SetId( ({ "glove" }) );
  SetShort("a boarskin glove");
  SetAdjectives( ({ "boarskin", "boar", "skin" }) );
  SetLong(
    "The glove was sewn from the thick leather hide of a boar. The fingers are thin "
    "enough to provide some dexterity, while the palm and wrist are covered in enough "
    "padding to stop a wolf's teeth."
  );
  SetMass(200);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(1250);
  SetDamagePoints(25000);
  SetArmourType(A_GLOVE);
  SetWear("The boarskin glove feels a little scratchy.");
}


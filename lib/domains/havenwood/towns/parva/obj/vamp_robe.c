#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "textile" }) );
  SetKeyName("robe");
  SetShort("a dirty sackcloth robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "dirty", "sackcloth" }) );
  SetLong(
    "This heavy robe is stained with a mottled pattern of blood and beer."
  );
  SetMass(40);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetValue(80);
  SetDamagePoints(200);
  SetMaterial("textile");
  SetWarmth(5);
  SetArmourType(A_BODY_ARMOUR);
}


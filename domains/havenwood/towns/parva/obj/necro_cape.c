
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
  SetKeyName("cape");
  SetShort("a dingy black cape");
  SetId( ({ "cape" }) );
  SetAdjectives( ({ "dingy", "black" }) );
  SetLong("This once regal cape is tattered and mottled with dirt. It looks "
    "like a well-tailored garment worn threadbare by someone who forgot "
    "how to bathe. Stars are embroidered in thin and often missing silver "
    "thread.");
  SetMass(40);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetValue(80);
  SetDamagePoints(200);
  SetMaterial("textile");
  SetWarmth(5);
  SetArmourType(A_CLOAK);
}


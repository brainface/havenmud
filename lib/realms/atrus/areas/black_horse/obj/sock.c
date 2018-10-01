#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("sock");
  SetShort("a comfortable sock");
  SetId( ({"sock"}) );
  SetAdjectives( ({"comfortable"}) );
  SetLong(
    "A single soft sock of medium size. ");
  SetMass(10);
  SetValue(50);
  SetDamagePoints(1000);
  SetMaterials( ({ "textile" }) );
  SetWarmth(15);
  SetArmourType(A_SOCK);
  SetRepairDifficulty(15);
}

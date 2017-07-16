
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_NATURAL);
  SetKeyName("cloak");
  SetShort("a furry bearskin cloak");
  SetId( ({"cloak"}) );
  SetAdjectives( ({"furry","bearskin"}) );
  SetLong(
    "This long and heavy cloak was made from the skin "
    "of some bear that picked the wrong fight. Almost "
    "oppressively warm, it should keep winter at bay, "
    "as well as quite a few sword blows.");
  SetMass(100);
  SetValue(1000);
  SetDamagePoints(2000);
  SetMaterials( ({ "natural" }) );
  SetWarmth(25);
  SetArmourType(A_CLOAK);
  SetRepairDifficulty(25);
}

//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("feather");
  SetId( ({ "feather" }) );
  SetAdjectives( ({ "blue" }) );
  SetShort("a blue feather");
  SetLong(
     "This is a small blue feather taken from the wing of "
     "a hawk. It is soft and quite pretty, although largely "
     "useless."
  );
  SetMass(3);
  SetMaterials( ({ "natural" }) );
  SetValue(10);
  SetClass(1);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
}

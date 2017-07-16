//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a large pot");
  SetId( ({ "pot" }) );
  SetAdjectives( ({ "large" }) );
  SetLong(
     "This amphora is painted with fishes and has two handles for "
     "easy gripping. It seems very sturdy and might even be useful "
     "as a weapon in a pinch."
  );
  SetClass(5);
  SetDamagePoints(350);
  SetValue(50);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("pot");
  SetMass(75);
  SetMaterial( ({ "natural" }) );
}

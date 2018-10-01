#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("glaive");
  SetId( ({"glaive"}) );
  SetShort("a glaive");
  SetLong(
     "This two handed weapon has a long wooden shaft with a large "
     "sharp blade on the top of the haft. The sharp blade resembles "
     "a large dagger on top of a staff. The staff is made from dark "
     "solid wood.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(700);
  SetClass(10);
  SetValue(250);
  SetMass(350);
  SetWeaponType("pole");
  SetDamageType(SLASH);
  SetMaterial( ({"wood", "metal"}) );
  SetRepairSkills( ([
     "wood working"    : 3,
     "metal working"   : 2,
     "weapon smithing" : 2,
     ]) );
  SetRepairDifficulty(6);
  SetHands(2);
}

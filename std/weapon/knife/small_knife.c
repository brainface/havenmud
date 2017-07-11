#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("small knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small knife");
  SetLong(
    "This knife looks like it would be better "
    "at carving apples rather then monsters."
  );
  SetClass(5);
  SetDamagePoints(200);
  SetValue(50);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(15);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "metal working" : 1,
  ]) );
  SetRepairDifficulty(18);
}

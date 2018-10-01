#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("dagger");
  SetShort("a blood dagger");
  SetLong(
    "A long dagger made of a hard red metal."
  );
  SetId( ({"dagger", "blood dagger"}) );
  SetAdjectives( ({ "long"}) );
  SetClass(12);
  SetDamagePoints(1750);
  SetValue(90);
  SetMass(45);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetRepairSkills( ([ 
    "weapon smithing" : 5 
  ]) );
  SetRepairDifficulty(12);
}

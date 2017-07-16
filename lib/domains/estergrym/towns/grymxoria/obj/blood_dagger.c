#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("blood dagger");
  SetShort("a blood dagger");
  SetId( ({ "dagger" }) );
  SetAdjectives( ({ "red", "blood", "long" }) );
  SetLong(
    "A long dagger made of a hard red metal."
  );
  SetClass(12);
  SetDamagePoints(1750);
  SetValue(90);
  SetMass(45);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "weapon smithing" : 5 
  ]) );
  SetRepairDifficulty(12);
}

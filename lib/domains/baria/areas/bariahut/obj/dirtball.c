//Alex@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create(){
  item::create();
  SetKeyName("dirt balls");
  SetId( ({ "balls", "ball" }) );
  SetAdjectives( ({ "set", "dirt", "of" }) );
  SetShort("a set of dirt balls");
  SetLong(
    "These few balls of dirt do little in the way of "
    "hurting anyone when thrown.");
  SetClass(5);
  SetDamagePoints(300);
  SetValue(10);
  SetWeaponType("projectile");
  SetDamageType(BLUNT);
  SetMass(50);
  SetMaterial( ({"natural"}) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(5);
}

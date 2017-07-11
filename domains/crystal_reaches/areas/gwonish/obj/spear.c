#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("spear");
  SetId( ({ "spear" }) );
  SetShort("a spear");
  SetLong("A heavy bronze spearhead caps the length of wood.");
  SetMaterial( ({"metal","wood"}) );
  SetRepairSkills( ([
                     "metal working" : 2,
                     "wood working" : 1,
                     "weapon smithing" : 2
                 ]) );
  SetRepairDifficulty(10);
  SetMass(175);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetClass(11,random(4));
  SetVendorType(VT_WEAPON);
}


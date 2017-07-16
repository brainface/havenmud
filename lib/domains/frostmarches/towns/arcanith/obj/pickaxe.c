// an iron pickaxe yo
// Mahkefel 2010
#include <lib.h>
#include <damage_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  digging::create();
  SetKeyName("pickaxe");
  SetId("pickaxe","axe");
  SetAdjectives( ({ "iron" }) );
  SetShort("an iron pickaxe");
  SetMaterials( ({ "metal" }) );
  SetLong("A well-used iron pickaxe. You could "
    "probably dig a pretty big hole with it.");

  SetClass(10);
  SetMass(100);
  SetValue(100);
  SetProperty("farming item", 1);
  SetDamagePoints(300);
  SetWeaponType("hack");
  SetDamageType(PIERCE);
}


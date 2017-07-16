#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a shard of broken glass");
  SetLong("This looks like it may once have been part of a small flask. "
          "Now broken, it has a number of sharp edges that could "
          "potentially be used in combat.");
  SetId( ({"shard","glass"}) );
  SetAdjectives("broken");
  SetClass(5);
  SetDamagePoints(200);
  SetValue(50);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetKeyName("knife");
  SetMass(15);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "natural" }) );
}

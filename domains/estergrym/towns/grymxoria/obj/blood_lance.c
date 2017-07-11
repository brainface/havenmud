#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("blood lance");
  SetId( ({"lance", "blood lance"}) );
  SetAdjectives( ({ "blood", "long"}) );
  SetShort("a blood lance");
  SetLong(
    "A long lance with a wooden shaft and a "
    "barbed point made of a hard red metal."
  );
  SetHands(2);
  SetClass(13);
  SetValue(300);
  SetMass(75);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1750);
  SetMaterial( ({ "metal", "wood" }) );
  SetRepairSkills( ([
    "weapon smithing" : 3,
    "wood working" : 1 
  ]) );
  SetRepairDifficulty(10);
}

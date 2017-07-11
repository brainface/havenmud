#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("wooden baton");
  SetId( ({ "baton", "stick" }) );
  SetAdjectives( ({ "wooden", "long", "thick" }) );
  SetShort("a long baton");
  SetLong(
    "Three and a half feet long and nearly two inches thick, "
    "this stick might make a formidable weapon."
  );
  SetMass(20); 
  SetValue(100);
  SetDamagePoints(1150);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(11);
  SetHands(2);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( ([
    "wood working" : 1,
    "metal working" : 1,
    "weapon smithing" : 1,
    ]) );
  SetRepairDifficulty(5);
}

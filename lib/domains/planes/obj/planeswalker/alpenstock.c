/*
* mahkefel 3/22
* planeswalker weapon
* fishing shovel beatstick.
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;
inherit LIB_POLE;

static void create() {
  item::create();
  SetKeyName("alpenstock");
  SetShort("a mithril-shod alpenstock");
  SetLong(
    "This alpenstock is a long wooden pole made for hiking. A gleaming"
    " spade-like tip at one end gives the wielder traction in rough"
    " terrain and could be used as a makeshift shovel or weapon in a"
    " pinch. A line of twine threaded through several hoops along"
    " the pole is probably used for fishing."
  );

  SetId( ({"staff","pole","alpenstock"}) );
  SetAdjectives(({""}));
  SetChance(80); //fishing
  SetClass(20);
  SetDamagePoints(3000);
  SetDamageType(PIERCE);
  SetHands(2);
  SetMass(50);
  SetMaterial( ({"mithril","wood" }));
  SetProperty("history",
    "Multi-purpose tools such as these are used by veteran explorers"
    " and travellers who may be stranded in places where magical"
    " conjurations of food and water are unavailable."
  );
  SetRepairDifficulty(100);
  SetStrength(4000); //fishing
  SetVendorType(VT_FISHING);
  SetValue(1000);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetWield("The alpenstock feels light and sturdy in your hands.");
}


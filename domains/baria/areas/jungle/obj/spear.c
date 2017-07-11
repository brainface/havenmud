/*  A sharp spear */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spear");
  SetShort("a crude spear");
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetHands(2);
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "crude" }) );
  SetMaterial( ({ "wood", "metal" }) );
  SetRepairSkills( ([
     "wood working" : 0,
     "metal working" : 0,
     "weapon smithing" : 0,
     ]) );
  SetLong("This is a crude wooden spear with a small metal tip on the end.");
  SetClass(2);
  SetMass(150);
  SetDamagePoints(900);
  SetValue(30);
  SetVendorType(VT_WEAPON);
  }

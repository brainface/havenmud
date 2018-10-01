#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetRepairSkills( ([
    "stone working" : 1,
    "weapon smith" : 1,
    ]) );
  SetProperty("magic", "The rapier is of heavenly origin.");
/*
  SetMaterial( ({ "mithril" }) );
*/
  SetShort("a finely crafted elven rapier");
  SetId( ({ "rapier", "fine rapier" }) );
  SetClass(18);
  SetMass(225);
  SetValue(1800);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetLong("This is a slightly glowing fine elven rapier.");
  SetRadiantLight(10);
  }

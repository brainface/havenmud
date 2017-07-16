// kobold denmother weapon
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("cane");
  SetId( ({ "cane" }) );
  SetAdjectives( ({ "short", "metal" }) );
  SetShort("a short metal cane");
  SetLong(
    "On closer inspection, this short cane is apparently the "
    "solid metal leg of some ancient automaton. The tripod-"
    "like legs that provide stability to the holder end in "
    "claws that haven't lost their edge to the years."
  );
  SetMass(20);
  SetValue(1000);
  SetDamagePoints(2000);
  SetWeaponType("pole");
  SetDamageType(BLUNT|PIERCE);
  SetClass(25);
  SetHands(1);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "mithril" }) );
  SetRepairSkills( ([
    "mithril working" : 1,
    "weapon smithing" : 1,
    ]) );
  SetRepairDifficulty(25);
}


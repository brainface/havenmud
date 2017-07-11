#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bow");
  SetMaterial("wood");
  SetShort("a short bow");
  SetId( ({ "short bow", "bow" }) );
  SetAdjectives( ({ "short" }) );
  SetLong("This small short bow is designed as a training bow "
          "for children");
  SetHands(2);
  SetValue(-1);
  SetClass(12);
  SetMass(40);
  SetDamageType(PIERCE);
  SetWeaponType("projectile");
  SetDamagePoints(600);
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "wood working" : 1,
    ]) );
  SetMaterial("natural");
}

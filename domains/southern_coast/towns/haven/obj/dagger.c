#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dagger");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
    ]) );
  SetMaterial( ({ "metal" }) );
  SetId( ({ "dagger", "small dagger" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small dagger");
  SetValue(200);
  SetMass(70);
  SetClass(12);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetLong("This is a small double edged dagger.");
  SetDamagePoints(600);
  }

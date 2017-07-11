// Orc invasion of Jidoor

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create() {
  item::create();
  SetKeyName("longsword");
  SetShort("a longsword");
  SetId( ({ "sword", "longsword" }) );
  SetAdjectives( ({ "long" }) );
  SetLong("A well-polished silver longsword.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(12);
  SetValue(250);
  SetMass(100);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(9);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
  ]) );
}

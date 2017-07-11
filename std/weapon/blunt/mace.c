#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mace");
  SetShort("a small mace");
  SetId( ({ "mace", "small mace" }) );
  SetAdjectives( ({ "small" }) );
  SetLong(
    "This is a small mace, which is a fine blunt weapon."
  );
  SetValue(0);
  SetDamagePoints(690);
  SetClass(10);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
    "metal working" : 1,
    "armour smithing" : 1
  ]) );
  SetRepairDifficulty(3);
  }

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("shortsword");
  SetId( ({ "sword", "shortsword" }) );
  SetAdjectives( ({"short", "small", "durable", "standard"}) );
  SetShort("a shortsword");
  SetLong(
    "A small, standard issue shortsword "
    "looks to be somewhat durable."
  );
  SetClass(9);
  SetDamagePoints(440);
  SetValue(80);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(55);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "metal working" : 1,
  ]) );
  SetRepairDifficulty(9);
}

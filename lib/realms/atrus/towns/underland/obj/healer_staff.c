#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "short" }) );
  SetShort("a short healer staff");
  SetLong(
    "This short staff would easily be a quarter staff to a human "
    "however to a gnome it is just over head height. Staff is surmounted "
    "by a priest-mace style head with a small blue glowing jewel in the center "
    "of it."
  );
  SetHands(2);
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT|WATER|MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1800);
  SetValue(8000);
  SetMass(125);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(75);
  SetRepairSkills( ([
    "wood working" : 90,
    "weapon smithing" : 90,
     ]) );
 }

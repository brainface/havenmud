#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("hammer");
  SetId( ({ "warhammer", "hammer", "justice" }) );
  SetAdjectives( ({ "war", "hammer", "justice", "emblazened" }) );
  SetShort("an emblazened warhammer");
  SetLong(
    "This warhammer is emblazed with the Kylin symbol.  The scales and dragon hammer "
    "bears the name \"Justice\" for its reknown in bringing order to those in need of it."
  );
  SetMaterial( ({"metal","wood"}) );
  SetRepairSkills( ([
    "wood working" : 3,
    "weapon smithing" : 4
  ]) );
  SetRepairDifficulty(10);
  SetMass(230);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(15);
  SetVendorType(VT_WEAPON);
}

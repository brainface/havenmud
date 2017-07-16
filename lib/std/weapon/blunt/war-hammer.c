#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("war-hammer");
  SetId( ({ "war-hammer","hammer" }) );
  SetAdjectives( ({ "heavy", "war"}) );
  SetShort("a heavy war-hammer");
  SetLong(
    "A heavy stone head caps a sturdy wooden handle, creating a "
    "formidable weapon"
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
  SetClass(12);
  SetVendorType(VT_WEAPON);
}

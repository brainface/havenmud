#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("hammer");
  SetId( ({ "hammer" }) );
  SetAdjectives( ({ "heavy"}) );
  SetShort("a heavy hammer");
  SetLong(
    "A heavy metal head caps a sturdy wooden handle, creating a "
    "formidable tool for a smith but also useable for a weapon "
    "in case of combat."
    );
  SetMaterial( ({"metal","wood"}) );
  SetRepairSkills( ([
    "metal working"   : 3,
    "wood working"    : 3,
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

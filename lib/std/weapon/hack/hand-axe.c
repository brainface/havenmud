#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("hand-axe");
  SetId( ({ "hand-axe","axe" }) );
  SetAdjectives( ({ "sharp","steel","bone","hand" }) );
  SetShort("a sharp hand-axe");
  SetLong(
    "A sharp steel head caps the bone handled axe."
  );
  SetMaterial( ({"metal","natural"}) );
  SetMass(230);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(12);
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(20);
  SetRepairSkills( ([
    "natural working" : 1,
    "metal working"   : 1,
    "weapon smithing" : 1,
  ]) );
}

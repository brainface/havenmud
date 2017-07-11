#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("hammer");
  SetId( ({"hammer" }) );
  SetAdjectives( ({ "steel"}) );
  SetShort("a steel hammer");
  SetLong(
    "This hammer is definitely a tool made for driving nails "
    "and not a weapon of war, but could probably still break "
    "a bone if swung with enough strength."
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
  SetClass(10);
  SetVendorType(VT_WEAPON);
}


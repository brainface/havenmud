#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("nail");
  SetId( ({"nail" }) );
  SetAdjectives( ({ "iron"}) );
  SetShort("an iron nail");
  SetLong(
    "This is a simple iron nail. It would probably hurt to "
    "be stabbed with it."
  );
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
    "wood working" : 3,
    "weapon smithing" : 4
  ]) );
  SetRepairDifficulty(10);
  SetMass(10);
  SetValue(50);
  SetDamagePoints(200);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetClass(5);
  SetVendorType(VT_WEAPON);
}


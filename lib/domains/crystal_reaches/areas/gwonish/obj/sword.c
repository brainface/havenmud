#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("sword");
  SetId( ({ "sword","longsword" }) );
  SetShort("a serrated longsword");
  SetAdjectives( ({ "serrated" }) );  // Added by Duuk
  SetLong("The blade of the longsword has tiny serrated teeth up and "
    "down it's length.");
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
                     "metal working" : 3,
                     "weapon smithing" : 3
                 ]) );
  SetRepairDifficulty(13);
  SetMass(325);
  SetValue(350);
  SetDamagePoints(2250);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(13,random(4));
  SetVendorType(VT_WEAPON);
}


#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("trident");
  SetId( ({ "trident" }) );
  SetShort("a trident");
  SetLong("Barbs tip each of the three prongs of the trident.");
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
                     "metal working" : 2,
                     "weapon smithing" : 2
                 ]) );
  SetRepairDifficulty(10);
  SetMass(200);
  SetValue(250);
  SetDamagePoints(1500);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetClass(13,random(3));
  SetVendorType(VT_WEAPON);
}


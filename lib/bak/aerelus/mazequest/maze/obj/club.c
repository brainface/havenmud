#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a gigantic wooden club");
  SetLong(
    "This massive weapon was obviously carved from a huge tree. It has been "
    "reinforced with durable steel poles, some of which stick out of the "
    "club, adding to the misery of anyone caught in its path. It looks a "
    "little worn, but still as deadly as it was on the day it was carved."
  );  
  SetId( ({"club"}) );
  SetAdjectives( ({ "gigantic", "wooden" }) );
  SetClass(28);
  SetDamagePoints(20000);
  SetValue(1500);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("club");
  SetMass(1400);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}


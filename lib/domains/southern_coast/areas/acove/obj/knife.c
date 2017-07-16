  /* knife
  Zara 8/14/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetShort("a razor-sharp knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({ "razor", "sharp", }) );
  SetLong("This razor-sharp knife is small but deadly.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(200);
  SetClass(14);
  SetValue(50);
  SetMass(20);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "weapon smithing" : 5,
     "metal working" : 5,
       ]) );
  SetRepairDifficulty(10);
}

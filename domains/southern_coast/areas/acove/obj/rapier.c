  /*rapier
  Zara 8/14/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetShort("a deadly rapier");
  SetId( ({"rapier"}) );
  SetAdjectives( ({"light","balanced","deadly"}) );
  SetLong("This rapier is light, well balanced, and "
          "a deadly weapon.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetClass(14);
  SetValue(300);
  SetMass(75);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);

  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
    "weapon smithing" : 30,
    "metal working" : 30,
      ]) );
  SetRepairDifficulty(40);
}

/* An old short sword - by Sardonas*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetId( ({ "rapier", "sword" }) );
  SetAdjectives( ({ "rusty", "old", "chipped" }) );
  SetShort("a chipped rapier");
  SetLong("The rapier is covered in rust and looks ready to fall apart.  "
          "The blade is old and chipped; it looks like someone tried to stab "
          "rocks with it.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(200);
  SetClass(6);
  SetValue(40);
  SetMass(100);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ "metal working" : 2,
                      "weapon smithing" : 1,
                 ]) );
  SetRepairDifficulty(7);
}

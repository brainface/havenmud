/* Weak kobold spear - made by Sardonas */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spear");
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "weak" }) );
  SetShort("a weak spear");
  SetLong("The spear is very short and almost harmless.  It was made with a "
          "very springy sapling, which allows much of the force to be "
          "absorbed by the spear's shaft.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(300);
  SetClass(5);
  SetValue(40);
  SetMass(80);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMaterial( ({ "wood", "natural" }) );
  SetRepairSkills( ([ "wood working" : 1,
                      "stone working" : 1,
                      "weapon smithing" : 1,
                 ]) );
  SetRepairDifficulty(5);

}

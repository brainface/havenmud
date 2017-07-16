/* an old knife - made by Sardonas */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "small", "rusty" }) );
  SetShort("a small, rusty knife");
  SetLong("Age has worn away this knife until it is nearly useless.  The "
          "blade is speckeled with the orange-red color of rust.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(50);
  SetClass(3);
  SetValue(0);
  SetMass(20);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ "metal working" :1,
                      "weapon smithing" : 1,
                 ]) );
  SetRepairDifficulty(5);
}

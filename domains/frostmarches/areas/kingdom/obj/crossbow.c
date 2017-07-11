
/* a crossbow
   Ela 4/19/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("crossbow");
  SetShort("a deadly crossbow");
  SetId( ({"crossbow","bow"}) );
  SetAdjectives( ({"deadly"}) );
  SetLong("This deadly crossbow has the marks of the Fae carved into it to "
          "bring good luck.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(15);
  SetValue(300);
  SetMass(40);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetMaterial( ({"wood"}) );
  SetRepairSkills( ([
           "weapon smithing" : 5,
          "wood working" : 5,
          ]) );
  SetRepairDifficulty(25);
}

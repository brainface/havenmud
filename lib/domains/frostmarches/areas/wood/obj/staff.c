/* a staff
  Ela 11/2/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("a rowan staff");
  SetId( ({"rowan staff","staff"}) );
  SetAdjectives( ({"rowan","long","magical"}) );
  SetLong("This long staff is crafted from a rowan tree, a tree that is "
         "highly favored among the Fae for its magical properties.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(17);
  SetValue(100);
  SetMass(40);
  SetWeaponType("pole");
  SetDamageType(MAGIC);
  SetMaterial( ({"wood"}) );
  SetRepairSkills( ([
           "wood working" : 7,
           "weapon smithing" : 7,
           ]) );
  SetRepairDifficulty(10);
}

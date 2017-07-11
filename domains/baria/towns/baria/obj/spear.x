/* free equip for hunters
     Kyla 11-2-97
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("a long spear");
  SetId( ({"spear"}) );
  SetAdjectives( ({ "long", "hollow", "deadly"}) );
  SetShort("a long spear");
  SetLong(
     "This long object is a hollowed out piece of wood that "
     "has been formed into a spear. The point of this weapon "
     "appears to have been made out of a simple piece of metal. "
     "The handle appears to be long, straight, and plain. It looks "
     "rather sharp. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1250);
  SetClass(9);
  SetValue(125);
  SetMass(180);
  SetMaterial( ({ "wood", "metal"}) );
  SetRepairSkills( ([
                  "wood working" : 3,
                  "metal working" : 3,
                   ]) );
  SetRepairDifficulty(10);
  SetWeaponType("pierce combat");
  SetDamageType(PIERCE);
  }

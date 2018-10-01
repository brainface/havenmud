/*   Portia   10-15-98
    A dagger for my prince.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dagger");
  SetShort("a handsome dagger");
  SetId( ({"dagger"}) );
  SetAdjectives( ({"handsome"}) );
  SetLong("This dagger looks to be very expensive, and "
          "very deadly. While it's outward appearance is "
          "one of beauty, it is obviously a dangerous weapon.");
  SetMass(25);
  SetClass(17);
  SetValue(90);
  SetDamagePoints(1500);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
        "metal working" : 9,
        "weapon smithing" : 9,
           ]) );
  SetRepairDifficulty(70);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  }

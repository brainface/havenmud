/* a dagger fo the old woman
     kyla 4-98
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dagger");
  SetShort("a jeweled dagger");
  SetId( ({"dagger" }) );
  SetAdjectives( ({"jeweled"}) );
  SetLong("This dagger looks as if it were made for a very rich and "
       "highly trained person. Not only is is beautiful, but it looks "
     "very deadly.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(600);
  SetClass(12);
  SetValue(100);
  SetMass(20);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
           "metal working" : 6,
           "weapon smithing" : 6,
                 ]) );
  SetRepairDifficulty(5);
  }

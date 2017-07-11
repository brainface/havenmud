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
  SetShort("a small dagger");
  SetId( ({"dagger" }) );
  SetAdjectives( ({"small"}) );
  SetLong("This dagger looks as if it has seen many battles and was very "
         "well cared for. It looks quite deadly.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(500);
  SetClass(11);
  SetValue(80);
  SetMass(15);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
           "metal working" : 6,
           "weapon smithing" : 6,
                 ]) );
  SetRepairDifficulty(5);
  }

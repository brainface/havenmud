/* a ceremonial rapier
    kyla 4-98
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetShort("a ceremonial rapier");
  SetId( ({"rapier"}) );
  SetAdjectives( ({"ceremonial"}) );
  SetLong("This finely crafted ceremonial rapier is quite obviously "
          "of high value due mainly to its highly jeweled and elaborate "
          "hilt.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(500);
  SetClass(10);
  SetMass(40);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMaterial( ({"metal" }) );
  SetRepairSkills( ([
           "metal working" : 6,
           "weapon smithing" : 6,
                ]) );
  SetRepairDifficulty(8);
  }

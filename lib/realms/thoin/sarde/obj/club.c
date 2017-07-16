/* free equip for shamans
    Kyla 11-2-97
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("club");
  SetId( ({"club"}) );
  SetAdjectives( ({"heavy"}) );
  SetShort("a heavy club");
  SetLong(
     "This large piece of wood looks to have been picked directly "
     "from the forest with little alteration. It appears to be a "
     "crude, but effective, weapon. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1100);
  SetClass(11);
  SetValue(120);
  SetMass(200);
  SetWeaponType("blunt");
  SetMaterial( ({"wood"}) );
  SetRepairSkills( ([
              "wood working" : 3,
                 ]) );
  SetRepairDifficulty(10);
  SetDamageType(BLUNT);
  }

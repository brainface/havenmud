/* a butcher knife for the cook
    kyla 4-98
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../mansion.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("butcher knife");
  SetShort("a butcher knife");
  SetId( ({"knife" }) );
  SetAdjectives( ({"butcher"}) );
  SetLong("This butcher knife looks as if it could cut through even "
          "the toughest piece of meat.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(300);
  SetClass(9);
  SetValue(70);
  SetMass(15);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMaterial( ({"metal" }) );
  SetRepairSkills( ([
          "metal working" : 3,
                ]) );
  SetRepairDifficulty(4);
  }

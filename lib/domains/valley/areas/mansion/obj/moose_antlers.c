/* moose antlers
  kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("antlers");
  SetId( ({
       "anteler", "antlers",
        }) );
  SetAdjectives( ({
       "moose", "large"
               }) );
  SetShort("a set of moose antlers");
  SetLong("These are very large antlers, apparently from rather large moose.");
  SetMass(110);
  SetValue(15);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"natural"}) );
  SetDamageType(PIERCE);
  SetWeaponType("pierce");
  SetDamagePoints(100);
  SetClass(10);
  SetHands(2);
  SetWield("The antlers make a clumsy weapon.");
  }

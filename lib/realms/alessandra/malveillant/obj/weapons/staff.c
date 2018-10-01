/*  Portia  10-15-98
    A staff for my mages.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("an ivory staff");
  SetId( ({"staff"}) );
  SetAdjectives( ({"ivory"}) );
  SetLong("This ivory staff is quite long and fairly heavy. "
          "It seems to be well crafted and is quite an attractive "
          "weapon.");
  SetClass(20);
  SetMass(100);
  SetValue(120);
  SetDamagePoints(1500);
  SetMaterial( ({"natural"}) );
  SetRepairSkills( ([
       "natural working" : 3,
        "weapon smithing" : 5,
       ]) );
  SetRepairDifficulty(30);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  }

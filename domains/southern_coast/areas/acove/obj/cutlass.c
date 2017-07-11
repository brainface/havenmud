  /* a cutlass
  Zara 8/14/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("cutlass");
  SetShort("a gleaming cutlass");
  SetId( ({"cutlass"}) );
  SetAdjectives( ({"gleaming","large","honed","deadly"}) );
  SetLong("This gleaming cutlass is large and curved. It "
        "is honed to perfection. Its great weight adds "
          "to its deadly force.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(16);
  SetValue(500);
  SetMass(300);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
    "weapon smithing" : 20,
     "metal working" : 20,
       ]) );
  SetRepairDifficulty(50);
}

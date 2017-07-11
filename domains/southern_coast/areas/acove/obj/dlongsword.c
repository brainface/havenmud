  /* double edged longsword
  Zara 8/14/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetShort("a double edged longsword");
  SetId( ({"longsword","sword"}) );
  SetAdjectives( ({"heavy","dense","sturdy","awesome"}) );
  SetLong("This sturdy sword is an awesome weapon "
       "in the right hands. It is heavy and dense.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2000);
  SetClass(16);
  SetValue(400);
  SetMass(400);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "weapon smithing" : 20,
     "metal working" : 20,
       ]) );
  SetRepairDifficulty(40);
}

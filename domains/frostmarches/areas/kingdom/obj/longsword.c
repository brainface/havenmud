
/* A longsword
   Ela 4/19/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetShort("a dashing longsword");
  SetId( ({"longsword","sword"}) );
  SetAdjectives( ({"dashing"}) );
  SetLong("This dashing sword reflects light in brilliant sparks.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(14);
  SetValue(100);
  SetMass(150);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
       "weapon smithing" : 8,
      "metal working" : 8,
         ]) );
  SetRepairDifficulty(25);
}

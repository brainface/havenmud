  /* A longsword
  Zara 8/14/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dashing longsword");
  SetShort("a dashing longsword");
  SetId( ({"longsword", "sword"}) );
  SetAdjectives( ({ "dashing" }) );
  SetLong("This dashing sword reflects light and is honed to a "
         "fine point.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(16);
  SetValue(400);

  SetMass(400);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
      "weapon smithing" : 8,
      "metal working" : 8,
        ]) );
  SetRepairDifficulty(25);
}

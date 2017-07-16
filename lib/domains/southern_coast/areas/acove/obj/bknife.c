  /*butcher knife
  Zara 8/14/98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("butcher knife");
  SetShort("a butcher knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({"butcher","sharp","large"}) );
  SetLong("This large butcher knife has been around "
          "for some time but the edges are razor-sharp.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(14);
  SetValue(50);
  SetMass(30);
  SetMaterial( ({"metal"}) );
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetRepairSkills( ([
    "weapon smithing" : 5,
    "metal working" : 5,
      ]) );
  SetRepairDifficulty(15);
}

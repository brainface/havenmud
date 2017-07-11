/* an axe for the mother
     KYLA 11-2-97
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("a massive axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({"massive"}) );
  SetShort("a massive axe");
  SetLong("This massive axe appears especially well designed for opening skulls of fallen foes.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2000);
  SetClass(35);
  SetValue(500);
  SetHands(2);
  SetMaterial( ({"metal", "wood"}) );
  SetRepairSkills( ([
    "metal working": 1
    ]) );
  SetRepairDifficulty(5);
  SetMass(120);
  SetWeaponType("hack");
  SetDamageType(SLASH);
}

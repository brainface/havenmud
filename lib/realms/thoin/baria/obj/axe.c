/* an axe for the mother
     KYLA 11-2-97
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("a small axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({"small"}) );
  SetShort("a small axe");
  SetLong("This small axe looks as if it were made strictly for cutting wood.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(950);
  SetClass(10);
  SetValue(50);
  SetMaterial( ({"metal", "wood"}) );
  SetRepairSkills( ([
                 "metal working": 1
                ]) );
  SetRepairDifficulty(5);
  SetMass(120);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  }

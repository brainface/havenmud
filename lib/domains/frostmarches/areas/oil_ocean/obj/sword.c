//Illura@haven
//Nov 2010
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spatha sword");
  SetShort("a spatha sword");
  SetId( ({"sword"}) );
  SetAdjectives( ({"spatha"}) );
  SetLong(
    "This spatha sword has a smooth brass hilt and a channeled steel "
    "blade. Notches and dents mar the surface of the blade from long "
    "use.");
  SetValue(80);
  SetClass(30);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetDamagePoints(1500);
  SetRepairSkills( ([
     "metal working" : 7,
     "weapon smithing" : 6,
     ]) );
  SetRepairDifficulty(20);
  SetMaterial( ({"metal"}) );
  SetMass(120);
  }


// modified by Dahaka
// Aug 2004


#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({"knife","thin knife"}) );
  SetAdjectives( ({"thin"}) );
  SetShort("a thin knife");
  SetLong(
     "This thin knife is one of the standard weapons of an Agent of "
     "the Council of Thirteen. This highly polished and sharpened "
     "knife appears it could be dangerous in the right hands."
     );
  SetDamagePoints(950);
  SetValue(200);
  SetMass(90);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetRepairDifficulty(25);
  SetRepairSkills( ([
     "metal working"   : 15,
     "weapon smithing" : 15,
     ]) );
  SetMaterial( ({"metal"}) );
}

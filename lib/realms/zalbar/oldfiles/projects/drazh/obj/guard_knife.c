// by Dahaka
// Aug 2004

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({"thin"}) );
  SetShort("a thin knife");
  SetLong(
     "This thin knife is the standard weapon of the town watch. The thin "
     "blade of this weapon makes it an excellent weapon for exploting weak "
     "spots in armour. This knife looks to be quite reliable. "
     );
  SetDamagePoints(950);
  SetValue(200);
  SetMass(90);
  SetClass(14);
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetWeaponType("knife");
  SetRepairDifficulty(20);
  SetRepairSkills( ([
     "metal working"   : 10,
     "weapon smithing" : 10,
     ]) );
  SetMaterial( ({"metal"}) );
}

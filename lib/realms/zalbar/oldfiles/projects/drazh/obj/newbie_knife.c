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
  SetDamagePoints(400);
  SetValue(15);
  SetMass(90);
  SetClass(4);
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetWeaponType("knife");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
     "metal working"   : 5,
     "weapon smithing" : 5,
     ]) );
  SetMaterial( ({"metal"}) );
}

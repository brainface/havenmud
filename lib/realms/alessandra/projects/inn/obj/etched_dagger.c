//   by Alessandra 9/04    //

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  
  SetKeyName("dagger");
  SetShort("an etched dagger");
  SetId( ({"dagger"}) );
  SetAdjectives( ({"etched"}) );
  SetLong(
     "This dagger has a long and wicked looking blade. Ancient "
     "runes are etched along either side of it, and the hilt is "
     "wrapped in black leather."
     );
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetDamagePoints(900);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 5,
     "weapon smithing" : 5,
     ]) );
  SetRepairDifficulty(30);
  SetClass(15);
  SetValue(200);
  SetMass(30);
}

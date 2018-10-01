#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({"staff"}) );
  SetAdjectives( ({"long"}) );
  SetShort("a long staff");
  SetLong(
	  "This long black staff has been reinforced with a small "
	  "red leather bands. The bands are wound tight around "
	  "the thin long wooden staff giving it greater resistance "
	  "to take damage."
	  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(400);
  SetClass(5);
  SetValue(25);
  SetMass(150);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMaterial( ({"wood", "leather"}) );
  SetRepairSkills( ([
     "wood working"    : 2,
     "leather working" : 2,
     "weapon smithing" : 3,
     ]) );
  SetRepairDifficulty(5);
  SetHands(2);
}



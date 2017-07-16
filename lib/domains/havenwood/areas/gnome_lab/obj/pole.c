#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("pole");
  SetId( ({"pole"}) );
  SetShort("a long pole");
  SetLong(
	  "This long pole has been reinforced with small "
	  "leather bands. The bands are wound tight around "
	  "the thin long wooden pole giving it greater "
	  "resistance to damage.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(500);
  SetClass(8);
  SetValue(50);
  SetMass(250);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMaterial( ({"wood", "leather"}) );
  SetRepairSkills( ([
     "wood working" : 3,
     "leather working" : 2,
     "weapon smithing" : 2,
     ]) );
  SetRepairDifficulty(6);
  SetHands(2);
  }

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a wooden ladel");
  SetLong("This is a wooden ladel used to stir up soups and other "
	"semi-liquid meals.  It is about fifteen inches in length "
	"and made of a light colored wood.  It is still damp from "
	"some mysterious liquid that it has stirred.");
  SetId( ({"ladel"}) );
  SetClass(3);
  SetDamagePoints(75);
  SetValue(3);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetKeyName("ladel");
  SetMass(10);
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( ([
	"wood working" : 1,
	]) );
  SetRepairDifficulty(1);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"wooden"}) );
}
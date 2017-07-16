#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a small spit");
  SetLong("This is a short piece of metal, pointed at one end and "
	"used to roast small animals over a fire pit.  It has been "
	"blackened from use and still has drippings on it from "
	"previous meals.  This could make an improvised weapon in "
	"a jam.");
  SetId( ({"spit"}) );
  SetClass(2);
  SetDamagePoints(100);
  SetValue(5);
  SetWeaponType("pole");
  SetDamageType(PIERCE);
  SetKeyName("spit");
  SetMass(15);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
	"metal working" : 1,
	]) );
  SetRepairDifficulty(2);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"small"}) );
}
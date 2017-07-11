#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a metal pot");
  SetLong("This is a large metal pot used to boil liquids in.  It is "
	"made of a cast metal that is black in color and has a wooden "
	"handle.");
  SetId( ({"pot"}) );
  SetClass(5);
  SetDamagePoints(90);
  SetValue(6);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetKeyName("pot");
  SetMass(18);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
	"metal working" : 3,
	]) );
  SetRepairDifficulty(3);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"metal"}) );
}
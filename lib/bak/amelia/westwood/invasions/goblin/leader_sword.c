#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a long sword");
  SetLong("This weapon is a very impressive long sword.  It is about "
	"forty-five inches long with a wire wrapped leather handle.  The "
	"edge is very sharp and looks like it could cleave a person in two.  "
	"There is a blood groove running the length of the blade and a "
	"serrated along both sides.");
  SetId( ({"sword"}) );
  SetClass(14);
  SetDamagePoints(750);
  SetValue(250);
  SetWeaponType("sword");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( (["metal working" : 4,
	"weapon smithing" : 4,
	"leather working" : 3, ]) );
  SetRepairDifficulty(9);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"long"}) );
}

/* Approved by Dylanthalus on Tue May 18 01:04:06 1999. */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a short sword");
  SetLong("This weapon is nothing more than a short sword.  It is "
	"about twenty-four inches long with a wooden handle.  The edge is "
	"very sharp and looks like it could cause some damage.  There is a "
	"thin blood groove running the length of the blade.");
  SetId( ({"sword"}) );
  SetClass(9);
  SetDamagePoints(400);
  SetValue(125);
  SetWeaponType("sword");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(155);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( (["metal working" : 1,
	"weapon smithing" : 1 ]) );
  SetRepairDifficulty(4);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"short"}) );
}

/* Approved by Dylanthalus on Tue May 18 01:05:57 1999. */
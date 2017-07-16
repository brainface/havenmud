#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a shiny red ball");
  SetLong("This is a shiny red ball.  It is about eight inches in "
	"diameter and made of a very flexible material.");
  SetId( ({ "ball" }) );
  SetClass(1);
  SetDamagePoints(50);
  SetValue(5);
  SetWeaponType("projectile");
  SetDamageType(BLUNT);
  SetKeyName("ball");
  SetMass(5);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(1);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "red","shiny" }) );
}
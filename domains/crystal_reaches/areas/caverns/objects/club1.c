/*  Club - Kobold - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("club");
  SetId( ({ "club" }) );
  SetAdjectives( ({ "wooden", "wood", "worthless" }) );
  SetShort("a club");

  SetLong("The club is actually nothing more than a large piece of gnarled "
          "wood that is narrow at one end so that one can hold it "
          "semicomfortably.  It looks totally worthless.");

  SetMass(110);
  SetValue(0);
  SetDamagePoints(180);

  SetVendorType(VT_WEAPON);
  SetMaterial("wood");

  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(5);
}
/*  Workers Hammer - Bridge Builder - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("workers hammer");
  SetId( ({ "workers hammer", "hammer" }) );
  SetAdjectives( ({ "workers", "ordinary" }) );
  SetShort("a workers hammer");

  SetLong("This is an ordinary workers hammer.  It has a large square head "
          "and a wooden handle... quite ordinary.  Although, the hammer could "
          "cause quite a bit of damage if wielded correctly.");

  SetMass(220);
  SetValue(150);
  SetDamagePoints(750);

  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal", "wood" }) );
  SetRepairSkills( ([ "metal working" : 1,
                      "weapon smithing" : 3,
                      "wood working" : 1,
  ]) );
  SetRepairDifficulty(4);

  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(7);
}

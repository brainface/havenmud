/*  Longsword - Kobold Chief - Level #1 Caverns */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("koboldish longsword");
  SetId( ({ "koboldish longsword", "longsword", "sword" }) );
  SetAdjectives( ({ "koboldish",  }) );
  SetShort("a koboldish longsword");

  SetLong("This is a very fine piece of craftmanship... for a kobold.  The "
          "blade is uneven in spots and the handle slightly crooked, but "
          "overall it is a fair sword.");

  SetMass(275);
  SetValue(120);
  SetDamagePoints(500);

  SetVendorType(VT_WEAPON);
  SetMaterial("metal");
  SetRepairSkills( ([ "metalworking" : 5,
                      "weapon smithing" : 5,
  ]) );
  SetRepairDifficulty(7);

  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(9);
}

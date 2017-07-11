#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_POLE;

static void create() {
  pole::create();
  SetKeyName("sturdy pole");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "wood working" : 1,
    ]) );
  SetMaterial( ({ "wood" }) );
  SetShort("a sturdy fishing pole");
  SetId( ({ "pole", "fishing pole", "sturdy pole" }) );
  SetLong("This is a sturdy fishing pole made of the finest quality "
          "wood and metal parts to be found anywhere.");
  SetStrength(300);
  SetChance(40);
  SetVendorType(VT_FISHING);
  SetDamagePoints(400);
  SetClass(8);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMass(125);
  SetValue(300);
  }

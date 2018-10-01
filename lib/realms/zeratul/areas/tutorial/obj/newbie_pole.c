#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_POLE;

static void create() {
  pole::create();
  SetKeyName("cheap pole");
  SetMaterial( ({ "wood" }) );
  SetShort("a cheap-looking fishing pole");
  SetId( ({ "pole" }) );
  SetAdjectives( ({ "cheap", "looking", "fishing" }) );
  SetLong("This is a sturdy fishing pole made of the finest quality "
          "wood and metal parts to be found anywhere.");
  SetStrength(100);
  SetChance(20);
  SetVendorType(VT_FISHING);
  SetDamagePoints(400);
  SetClass(4);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMass(125);
  SetValue(000);
  SetRepairDifficulty(5);
  }

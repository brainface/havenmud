/*  A big club */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("club");
  SetShort("a large club");
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( ([ ]) );  /*  This cannot be repaired. */
  SetRepairDifficulty(0);
  SetClass(10);
  SetDamagePoints(600);
  SetValue(20);
  SetMass(80);
  SetId( ({ "club" }) );
  SetAdjectives( ({ "large" }) );
  SetLong("This is a large wooden club, suitable for hitting things with.");
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
  SetVendorType(VT_WEAPON);
  }

/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() 
{
item::create();
  SetKeyName("axe");
  SetId( ({ "hand axe","axe" }) );
  SetAdjectives( ({"serrated"}) );
  SetShort("a hand axe");
  SetLong("The hand axe's blade has a serrated edge to inflict more damage.");
  SetMass(150); 
  SetValue(150);
  SetDamagePoints(1500);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(12);
  SetVendorType(VT_WEAPON);
  SetMaterial("metal");
  SetRepairDifficulty(80);
}


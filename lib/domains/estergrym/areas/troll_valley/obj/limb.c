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
  SetKeyName("broken limb");
  SetId( ({ "limb"}) );
  SetAdjectives( ({"broken"}) );
  SetShort("a broken limb");
  SetLong("The limb looks as though it was ripped from a tree.");
  SetMass(150); 
  SetValue(150);
  SetDamagePoints(500);
  SetWeaponType("hack");
  SetDamageType(BLUNT);
  SetClass(8);
  SetVendorType(VT_WEAPON);
  SetMaterial("natural");
  SetRepairDifficulty(80);
}


/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() 
{
item::create();
  SetKeyName("bone");
  SetId( ({ "bone"}) );
  SetAdjectives( ({"clean","long"}) );
  SetShort("a clean bone");
  SetLong("The long bone has had all the meat stripped off of it.");
  SetMass(150); 
  SetValue(150);
  SetDamagePoints(500);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(9);
  SetMaterial("natural");
  SetRepairDifficulty(80);
}


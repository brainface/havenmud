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
  SetKeyName("jagged rock");
  SetId( ({ "rock"}) );
  SetAdjectives( ({"jagged"}) );
  SetShort("a jagged rock");
  SetLong("The.");
  SetMass(150); 
  SetValue(0);
  SetDamagePoints(500);
  SetWeaponType("projectile");
  SetDamageType(BLUNT);
  SetClass(2);
  SetMaterial("natural");
  SetRepairDifficulty(80);
}

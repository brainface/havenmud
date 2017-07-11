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
  SetId( ({ "battleaxe","battle axe","axe" }) );
  SetShort("a battleaxe");
  SetLong("On a staff of hardened oak a heavy blade of dwarven steel rests.");
  SetMass(400); 
  SetValue(150);
  SetDamagePoints(700);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(14);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 6,
     "weapon smithing" : 7
     ]) );
  SetRepairDifficulty(10);
}


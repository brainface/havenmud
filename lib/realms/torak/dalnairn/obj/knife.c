// Dalnairn
// Aerelus
//
// torak@haven 2019
// edited sword.c to knife.c for dalnairn recode

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetShort("a glistening knife");  
  SetLong(
    "This beautiful knife glistens as the ambient light reflects from "
    "the tiny shards of obsidian which have been infused into the metal. "
    "Clearly the work of a master smith, this weapon is both visually "
    "appealing and practical.",    
  );
  SetAdjectives( ({ "glistening" }) );
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetClass(25); // torak 2012 formerly 15
  SetDamagePoints(1000);
  SetValue(600);
  SetMass(100);
  SetMaterial("metal");
  SetRepairSkills( ([ 
    "weapon smithing" : 1,
    "metal working" : 1,
  ])  );
  SetRepairDifficulty(15);
  SetVendorType(VT_WEAPON);
}

// Dalnairn
// Aerelus

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sword");
  SetId( ({ "sword" }) );
  SetShort("a glistening sword");  
  SetLong(
    "This beautiful sword glistens as the ambient light reflects from "
    "the tiny shards of obsidian which have been infused into the metal. "
    "Clearly the work of a master smith, this weapon is both visually "
    "appealing and practical.",    
  );
  SetAdjectives( ({ "glistening" }) );
  
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(15);
  SetDamagePoints(1000);
  SetValue(600);
  SetMass(100);
  SetMaterial("metal");
  SetRepairDifficulty(15);
  SetVendorType(VT_WEAPON);
}

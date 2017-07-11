// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../karak.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe", "battleaxe" }) );
  SetAdjectives( ({ "large", "black" }) );
  SetShort("a large black battleaxe");
  SetLong(
    "This is a large battleaxe, formed of entirely of black metal, which "
    "appears to have been forged as one large piece. Simple scrollwork "
    "stands out near the bottom of the handle, not decorative, but instead "
    "intended to increase the wielder's grip when this weapon is used in "
    "battle and soaked in blood and gore."
  );
  SetWeaponType("hack");
  SetDamageType(SLASH);  
  SetVendorType(VT_WEAPON);
  SetDamagePoints(700);
  SetClass(14);
  SetValue(300);
  SetMass(200);
  SetMaterials( ({ 
  	"metal"
  }) );
  SetRepairDifficulty(22);
}

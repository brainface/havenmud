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
  SetKeyName("flail");
  SetId( ({ "flail" }) );
  SetAdjectives( ({ "large", "black" }) );
  SetShort("a large flail");
  SetLong(
    "This large flail is formed of a dark and sturdy wood, attached by a "
    "black chain to a spiked ball. The piece of wood is the length of "
    "a forearm and the spiked ball is the size of a spread hand. Rings "
    "are cut in to the far end of the wood, intended to improve grip for "
    "the wielder."
  );
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(16);
  SetValue(1000);
  SetMass(300);
  SetMaterials( ({ 
  	"metal",
  	"wood"
  }) );
  SetRepairDifficulty(22);
}

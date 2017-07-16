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
  SetAdjectives( ({ "wickedly", "spiked" }) );
  SetShort( "a wickedly spiked flail");
  SetLong(
    "This flail is constructed along normal lines, with a wooden handle "
    "attached by a chain to a spiked ball. Unlike other flails, which have "
    "simple straight spikes, the ones on this flail are truly wicked, having "
    "multiple serrated edges on each spike. Circular cuts on the handle "
    "are designed to improve grip onces the spikes have done their work and "
    "coated the weapon and wielder with gore and blood."
  );
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(700);
  SetClass(14);
  SetValue(300);
  SetMass(200);
  SetMaterials( ({ 
  	"metal",
  	"wood"
  }) );
  SetRepairDifficulty(22);  
}

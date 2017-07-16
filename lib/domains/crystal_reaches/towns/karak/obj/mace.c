// Karak Recode
// Laoise
// 2007

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create () {
  item::create();
  SetKeyName("mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "spiked" }) );
  SetShort("a spiked mace");
  SetLong(
    "This weapon consists of a pole with a heavy metal sphere attached to "
    "the end. There are several nasty looking spikes protruding from the "
    "sphere which would inflict extra damage on an opponent. Ridges and "
    "valleys decorate the handle, designed to improve grip for the wielder."
  );
  SetWeaponType("blunt");
  SetDamageType(BLUNT|PIERCE);
  SetVendorType(VT_WEAPON);
  SetMass(250);
  SetClass(16);
  SetValue(300);
  SetMaterial( ({ 
  	"metal" 
  }) );
  SetRepairDifficulty(20);  
}

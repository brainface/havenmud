// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("broadsword");
  SetShort("an ethereal broadsword");
  SetId( ({"broadsword"}) );
  SetAdjectives( ({ "ethereal" }) );    
  SetLong(
    "This broadsword is made up of pure energy. Green swirls of light "
    "dance in an intricate, ever changing pattern. This weapon is a "
    "thing of beauty."    
  	);
  SetMass(100);
  SetValue(600);
  SetClass(25);
  SetMaterial("mithril");
  SetRepairDifficulty(99);
  SetWeaponType("slash");
  SetDamageType(SHOCK);
  SetVendorType(VT_WEAPON); 
  SetDamagePoints(3000);
  SetRadiantLight(15);
}

// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetShort("an elegant knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({ "elegant" }) );    
  SetLong(
    "This is a long and elegant knife. Unlike most "
    "things in the sewers, this knife is well kept and "
    "very sharp."
  	);
  SetMass(45);
  SetValue(50);
  SetClass(18);
  SetMaterial("metal");
  SetRepairDifficulty(10);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON); 
  SetDamagePoints(1400);
}

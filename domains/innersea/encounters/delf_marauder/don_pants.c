#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("leather pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "pair of", "tough", "leather", "black", "tight", "skin tight" }) );
  SetShort("a pair of tough leather pants");
  SetLong(
     "Skin tight in a way that would make most males uncomfortable, "
     "these pants are very well crafted from a tough black leather. "
     "Designed for the discerning scoundrel, with flexibility and stealth "
     "in mind."
     );
  SetWear("A bit of a dandy, are we?");
  SetMass(150);
  SetWarmth(5);
  SetValue(600);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3500);
  SetRepairDifficulty(25);
  
}

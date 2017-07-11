#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("corset");
  SetId( ({ "corset" }) );
  SetAdjectives( ({ "leather", "laced", "black" }) );
  SetShort("a tightly laced corset");
  SetLong(
     "Blood red leather string criss-crossing the back cinches this "
     "black leather corset together tightly, ending in a bow at the waist. "
     "The rigidity of the leather both slims the waist to nearly non-existent "
     "proportions and has the added advantage of a more robust bustline."
     );
  SetWear("You gasp for air as the laces are tightened.");
  SetMass(50);
  SetWarmth(3);
  SetValue(250);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_VEST);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(20);
  
}

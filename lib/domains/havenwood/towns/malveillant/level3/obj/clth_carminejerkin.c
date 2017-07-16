//  Fancy Jerkin for Clothier
//  Desc by Vaash - Alessandra 2009

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  
  SetKeyName("jerkin");
  SetShort("a carmine sleeveless leather jerkin");
  SetId( ({"jerkin"}) );
  SetAdjectives( ({"carmine", "sleeveless", "leather"}) );
  SetLong(
     "This thin leather jerkin has no sleeves, and is a rich carmine in "
     "color. It is trimmed in black leather cording, and has small bone "
     "buttons carefully carved in the appearance of tiny skulls to fasten "
     "it closed."         
     );
  SetMass(35);
  SetWarmth(8);
  SetSize(SIZE_MEDIUM);
  SetValue(1200);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetDamagePoints(900);
  SetMaterial("leather");
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_VEST);

}

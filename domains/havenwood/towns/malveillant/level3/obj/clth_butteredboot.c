//  Fancy Boots for Clothier
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
  
  SetKeyName("boots");
  SetShort("a pair of silver-buttoned black leather boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({"silver-buttoned", "black", "leather"}) );
  SetLong(
     "Midnight black and polished to a reflective shine, these leather boots "
     "rise to just below the knee before folding over in a cuff. Small silver "
     "buttons in the shape of tiny roses run down the outsides."         
     );
  SetMass(25);
  SetWarmth(5);
  SetSize(SIZE_MEDIUM);
  SetValue(900);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetProperty("multiples", 1);
  SetDamagePoints(800);
  SetMaterial("leather");
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BOOT);

}

//  Fancy Gloves for Clothier
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
  
  SetKeyName("glove");
  SetShort("a black leather glove with silver stitching");
  SetId( ({"glove"}) );
  SetAdjectives("black","leather");
  SetLong(
      "Elegant silver stitching adorns the back of these gloves, which "
      "are sewn of a very soft and supple leather.  It is quite snug "
      "across the fingers and the hand, and then flares out partially "
      "to help guard the forearm."         
     );
  SetMass(15);
  SetWarmth(2);
  SetSize(SIZE_MEDIUM);
  SetValue(500);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetDamagePoints(200);
  SetMaterial("leather");
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_GLOVE);

}

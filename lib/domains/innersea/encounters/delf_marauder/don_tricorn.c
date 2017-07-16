#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("tricorne");
  SetId( ({ "tricorne", "hat" }) );
  SetAdjectives( ({ "leather", "black" }) );
  SetShort("a black leather tricorne");
  SetLong(
     "This black hat rests jauntily on its wearer's head, the supple "
     "leather brim pinned up on either side and in the back. A "
     "cockade of red leather bearing the Soirin black rose pins "
     "a coal black raven plume to the side of the tricorne."
     );
  SetMass(50);
  SetWarmth(2);
  SetValue(1000);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_class.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  ::create();
  SetKeyName("headband");
  SetId( ({ "headband" }) );
  SetAdjectives( ({ "wool" }) );
  SetShort("a wool headband");
  SetLong("This headband appears to have been hand crafted by "
          "knitting wool yarn together. The headband has a "
          "slight stretchy quality to it to adapt to most "
          "smaller sized head sizes. The wool is of cheap "
          "quality as stray threads pluck out from the "
          "initial strands.");
  SetWear("The wool headband hugs your cranium.");
  SetMass(15);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetWarmth(10);
  SetValue(random(50)+100);
  SetDamagePoints(400);
  SetArmourType(A_VISOR);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(20);

}
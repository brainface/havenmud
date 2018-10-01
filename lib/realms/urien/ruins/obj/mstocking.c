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
  SetKeyName("stocking");
  SetId( ({ "stocking" }) );
  SetAdjectives( ({ "linen","dark" }) );
  SetShort("a dark linen stocking");
  SetLong("This linen stocking is made of stretchy cloth which "
          "would adapt to comfortably fit a small persons leg. "
          "The stocking is a dark grey colour and has few abrasions "
          "along the surface. The exterior is slightly shiny when "
          "stretched and dull around the foot portion. Inside "
          "the stocking, the material has been pressed and compacted "
          "as if it has seen quite the amount of use over time.");
  SetMass(15);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetWarmth(10);
  SetValue(200);
  SetDamagePoints(1000);
  SetArmourType(A_LONG_SOCK);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(10);
  SetProtectionBonus(BLUNT, 1);
  SetProtectionBonus(PIERCE, -1);
  SetProtectionBonus(SLASH, -1);
}
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  ::create();
  SetKeyName("metal ring");
  SetId(( { "ring","polished","metal ring"} ));
  SetShort("a polished metal ring");
  SetLong("This small metal ring is remarkably stunning. It "
          "lacks any decor along the outside and the inside has "
		  "quality striations that provide solid durability to "
		  "the wearer.");
  SetMass(1);
  SetValue(85);
  SetDamagePoints(950);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_SMALL);
    
  SetArmourType(A_RING);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetProtectionBonus(POISON, 5);
  SetProtectionBonus(PIERCE, -5);
  SetWear("The polished metal ring glides on your finger easily.");
}
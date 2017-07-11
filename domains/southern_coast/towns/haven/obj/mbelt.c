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
  SetKeyName("belt");
  SetId( ({ "belt" }) );
  SetAdjectives( ({ "reinforced","wooden" }) );
  SetShort("a reinforced wooden belt");
  SetLong("A thin piece of leather makes up the belts main "
          "component which allows flexibility to the wearer. Two "
          "handmade knotches have been poked through the surface "
          "for adaptation of size. A bone buckle has been shaved "
          "at one end to fasten to the knotches. This belt appears "
          "small enough to fit a child. Along the outside, several "
          "planks of wood have been sewn onto the leather to allow "
          "the wearer some form of increased protection.");
  SetMass(15);
  SetMaterial("wood");
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_SMALL);
  SetWarmth(10);
  SetValue(150);
  SetDamagePoints(1200);
  SetArmourType(A_BELT);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(10);
  SetProtectionBonus(BLUNT, 3);
  SetProtectionBonus(HEAT, -5);
  SetProtectionBonus(PIERCE, 1);
}
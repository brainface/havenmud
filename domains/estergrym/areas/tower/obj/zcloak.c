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
  SetKeyName("cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "black","dark" }) );
  SetShort("a dark black cloak");
  SetLong("This dark black cloak holds a triangular shape. On the inside "
          "is a thin layer of plush rabbit fur. The outside of the cloak "
          "is dark black with no distinct markings or designs on it. With "
          "the exception of the fur on the inside, this cloak is plain.");
  SetMass(25);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_SMALL);
  SetWarmth(15);
  SetValue(65);
  SetDamagePoints(650);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(10);
}
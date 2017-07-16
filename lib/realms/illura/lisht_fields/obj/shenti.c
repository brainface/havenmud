//Illura@Haven
//Sept 2009
//shenti
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("shenti");
  SetId(( { "shenti","pants", "pair"} ));
  SetAdjectives( ({ "linen", "old" }) );
  SetShort("a pair of old linen shenti");
  SetLong(
    "This worn linen sheet wraps around the legs and abdomen, "
    "keeping one comfortably cool and protected from the "
    "elements. It has definitely been washed several times in "
    "less than sanitary conditions, taking on a yellowed hue.");
  SetMass(30);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(20);
  SetValue(70);
  SetDamagePoints(700);
  SetArmourType(A_PANTS);
}

//Selket@Haven
//2006
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
  SetId(( { "shenti","pants"} ));
  SetAdjectives( ({ "linen" }) );
  SetShort("linen shenti");
  SetLong(
    "This fine linen sheet wraps around the legs and abdomen, "
    "keeping one comfortably cool and protected.");
  SetMass(30);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetWarmth(20);
  SetValue(80);
  SetDamagePoints(700);
  SetArmourType(A_PANTS);
}

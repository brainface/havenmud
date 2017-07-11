//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include "../lisht.h"
inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("leather sandals");
  SetShort("a pair of leather sandals");
  SetId( ({ "sandals" }) );
  SetAdjectives(  ({ "leather", "pair", "pair of" })  );
  SetLong(
    "These leather sandals protect a the wearer's feet while "
    "walking on the sand in the desert sunlight."
  );
  SetMass(75);
  SetValue(50);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "leather" }) );
  SetWarmth(5);
  SetDamagePoints(500);
  SetArmourType(A_BOOT);
  SetProperty("multiples", 1);
  SetVendorType(VT_ARMOUR);
}

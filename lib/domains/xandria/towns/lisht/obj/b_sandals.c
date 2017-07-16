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
  SetKeyName("bronze sandals");
  SetShort("a pair of bronze sandals");
  SetId( ({ "sandals" }) );
  SetAdjectives(  ({ "bronze", "pair", "pair of" })  );
  SetLong(
    "These heavy sandals protect a soldier's feet while "
    "glinting dully in the desert sunlight."
  );
  SetMass(75);
  SetValue(50);
   SetArmourClass(ARMOUR_LEATHER);
   SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "leather", "metal" }) );
  SetWarmth(5);
  SetDamagePoints(500);
  SetArmourType(A_BOOT);
  SetProperty("multiples", 1);
  SetVendorType(VT_ARMOUR);
}

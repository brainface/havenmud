#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
   armour::create();
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "leather","pair of","old","poorly made","poor make" }) );
   SetShort("a pair of leather pants");
   SetLong("These leather pants look old, and of poor make.");
   SetMass(30);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
   SetMaterial("leather");
   SetWarmth(20);
   SetValue(150);
   SetDamagePoints(500);
   SetArmourType(A_PANTS);
}

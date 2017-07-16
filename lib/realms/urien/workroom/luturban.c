#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("turban");
   SetId( ({ "clean" }) );
   SetAdjectives( ({ "black" }) );
   SetShort("a clean black turban");
   SetLong(
   "This headwrap has been made quite professionally "
   "and appears very durable. A bright blue gem rests "
   "in the center giving off a soft hue of light. A dark "
   "blue feather sits in the gem standing proudly untouched "
   "and in perfect condition. The black wrapping that makes "
   "up this headpiece has been well protected by a thin wax "
   "coating on the outside and it maintains its size and "
   "shape by holding itself up."
   );
   SetVendorType(VT_ARMOUR);
   SetMass(50);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetValue(90);
   SetDamagePoints(3000);
   SetMaterial( ({ "textile" }) );
   SetArmourType(A_HELMET);
   SetWarmth(5);
   SetRepairDifficulty(10);
}
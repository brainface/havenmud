#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("boots");
  SetShort("a pair of plate mail boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "mail","plate" }) );
  SetArmourType(A_BOOT);
  SetSize(SIZE_MEDIUM);
  SetLong("This pair of metal boots appears to be extremely durable and would protect "
    "the wearer well. On the sides of the boots two suns are etched into the metal. ");
  SetValue(1500);
  SetMass(75);
  SetDamagePoints(25000);
  SetArmourClass(ARMOUR_PLATE);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(85);
  SetProperty("multiples", 1);
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
 }

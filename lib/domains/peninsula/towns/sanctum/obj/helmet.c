#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("helmet");
  SetShort("a plate mail helmet");
  SetId( ({ "helmet" }) );
  SetAdjectives( ({ "mail","plate" }) );
  SetArmourType(A_HELMET);
  SetSize(SIZE_MEDIUM);
  SetLong("The metal helmet appears to be extremely durable and would protect "
    "the wearer well. On the sides of the helmet two suns are etched into the metal. "
    "The helmet covers most of the face of the wearer offering more protection.");
  SetValue(1500);
  SetMass(100);
  SetDamagePoints(25000);
  SetArmourClass(ARMOUR_PLATE);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(85);
 }

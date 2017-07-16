// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("ethereal armour");
  SetShort("a suit of ethereal armour");
  SetId( ({ "armour", "suit" }) );
  SetAdjectives( ({ "ethereal" }) );
  SetLong(
    "This suit of armour is made up of pure energy. Green swirls of light "
    "dance in an intricate, ever changing pattern. It seems to offer a great "
    "deal of protection to the wearer."
  );
  SetMass(800);
  SetValue(800);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetVendorType(VT_ARMOUR);  
  SetDamagePoints(200);
  SetSize(SIZE_MEDIUM);
  SetRadiantLight(15);
}

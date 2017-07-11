#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include "../path.h"

inherit LIB_ARMOUR;

static void create()
{
  ::create();
  SetKeyName("cloak");

  SetId(( { "cloak" } ));
  SetAdjectives( ({ "dark","grass","herben","knit","black" }) );
  SetShort("a dark cloak");
  SetLong("The cloak is made from a variety of grasses and herbs that "
          "have been knit tightly together and dyed black.");
  SetMass(25);
  SetSize(SIZE_SMALL);
  SetValue(20);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(200);
  // SetProtection(PIERCE,1);
  // SetProtection(SLASH,1);
  // SetProtection(COLD,5);
  // SetProtection(HEAT,2);
  // SetProtection(ACID,2);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("You feel oddly at peace with your natural surroundings.");
  SetMaterial( ({ "natural" }) );
  SetWarmth(20);
  SetRepairDifficulty(1);
  SetRepairSkills( ([
    "natural working" : 3,
    "armour smithing" : 1,
  ]) );
}

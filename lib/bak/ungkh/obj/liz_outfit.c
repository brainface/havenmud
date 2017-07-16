#include <lib.h>
#include "../ungkh.h"
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("outfit");
  SetId( ({ "outfit" }) );
  SetAdjectives( ({ "blacksmith's" }) );

  SetShort("a blacksmith's outfit");
  SetLong(
         "Built for one reason and one reason only, this outfit "
          "was crafted to protect against the heat of a blacksmith's.  "
          "It is made of leather and covers most of the body.");


  SetVendorType(VT_CLOTHING);
  SetWarmth(15);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(700);
  SetArmourType(A_ARMOUR);

  // SetProtection(HEAT, 3);
  // SetProtection(PIERCE, 3);

  SetMaterial("leather");
  SetMass(250);

  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "armour smithing" : 4,
    "leather working" : 3,
    ]) );

  SetValue(125);

}

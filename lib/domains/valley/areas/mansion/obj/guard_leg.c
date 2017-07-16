/* leggings for the guards
     kyla 9-98
*/
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include "../mansion.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leggings");
  SetShort("a pair of leather leggings");
  SetId( ({"leggings"}) );
  SetAdjectives( ({"pair", "pair of", "leather"}) );
  SetLong("These leather leggings look as though they might be "
           "of high quality and belong to someone with much authority.");
  SetMass(60);
  SetVendorType(VT_ARMOUR);
  SetValue(100);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(700);
  // SetProtection(SLASH, 8);
  // SetProtection(PIERCE, 8);
  // SetProtection(BLUNT, 10);
  // SetProtection(COLD, 7);
  SetArmourType(A_PANTS);
  SetMaterials( ({"leather"}) );
  SetWarmth(20);
  SetRepairSkills( ([
        "leather working" : 9,
          ]) );
  SetRepairDifficulty(10);
  }

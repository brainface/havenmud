//
// A patterned silk scarf
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
   SetKeyName("silk scarf");
   SetId( ({ "scarf" }) );
   SetAdjectives( ({ "silk", "patterned" }) );
   SetShort("a silk scarf");
   SetLong("This patterned silk scarf is quite long, and could wrap around "
     "one's neck several times in a rather stylish manner. The patterns "
     "on the scarf are unlike any you have ever seen. The colors weave "
     "in and out of each other fluidly.");
   SetMass(2);
   SetMaterial("textile");
   SetWarmth(5);
   SetArmourClass(ARMOUR_CLOTH);
   SetValue(45);
   SetDamagePoints(50);
   SetArmourType(A_AMULET);
   SetVendorType(VT_CLOTHING);
   SetRepairDifficulty(5);
}

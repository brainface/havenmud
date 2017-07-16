//
// a purple velvet hat
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include "../bazaar.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
   SetKeyName("velvet hat");
   SetId( ({ "hat" }) );
   SetAdjectives( ({ "velvet" }) );
   SetShort("a velvet hat");
   SetLong("This dainty velvet hat has a curled up brim and a long "
     "feather sticking out of the top.");
   SetMass(35);
   SetMaterial("textile");
   SetWarmth(4);
   SetValue(100);
   SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(250);
   SetArmourType(A_HELMET);
   SetVendorType(VT_CLOTHING);
}

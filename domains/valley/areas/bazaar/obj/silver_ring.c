//
// a pretty silver ring
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
   SetKeyName("silver ring");
   SetId( ({ "ring" }) );
   SetAdjectives( ({ "silver" }) );
   SetShort("a silver ring");
   SetLong("This beautifully crafted silver ring sparkles in the light. It is "
     "a simple band with little dragons carved into the surface all the "
     "way around.");
   SetMass(1);
   SetMaterial("metal");
   SetRepairDifficulty(10);
   SetWarmth(0);
   SetArmourClass(ARMOUR_CHAIN);
   SetValue(200);
   SetVendorType(VT_TREASURE | VT_ARMOUR);
   SetWear("The ring fits snugly onto your finger.");
   SetArmourType(A_RING);
   SetDamagePoints(100);
   
}

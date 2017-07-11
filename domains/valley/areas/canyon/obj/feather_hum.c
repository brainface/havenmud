#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hummingbird feather");
   SetShort("a hummingbird feather");
   SetId( ({ "feather" }) );
   SetAdjectives( ({ "humminbird","bird" }) );
   SetLong("Many colors decorate the humming bird feather.");
   SetMass(1);
   SetValue(15);
   SetVendorType(VT_TREASURE|VT_CLOTHING);
   SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(100);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   SetMaterial( ({ "natural" }) );
   SetWarmth(4);
   SetRepairDifficulty(12);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "natural working" : 1,
                  ]) );
}


/* Approved by Zaxan on Sat Jan 17 02:40:23 1998. */

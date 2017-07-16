#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_SMELL;
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hat");
   SetShort("a simple green hat");
   SetId( ({ "hat" }) );
   SetAdjectives( ({ "simple","green" }) );
   SetLong("The hat is a simple green color similar to that "
           "of the sea when it's full of bunches of little "
           "living things.  It has a flap in the front to "
           "protect one's eyes from the sun.  A few brown "
           "hairs cling to the inside.");
   SetMass(5);
   SetValue(15);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_HELMET);
   SetDamagePoints(25);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,5);
   // SetProtection(HEAT,2);
   SetSmell("The hat stinks of fish and the ocean.");
   SetWear("It's a little damp and wet.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(5);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}

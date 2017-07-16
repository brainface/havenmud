// Amelia@Haven
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a brown shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "shirt","brown","plain" }) );
   SetLong("This shirt is a plain brown color.  It was made from a "
           "thin, yet relative to other thin materials, is quite "
           "strong.");
   SetMass(10);
   SetValue(25);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(90);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,1);
   SetWear("The material is soft.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","A Parvan citizen once owned this shirt.");
}

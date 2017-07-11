#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of red boots");
   SetId( ({ "boot","boots" }) );
   SetAdjectives( ({ "pair of","red","bright" }) );
   SetLong("The bright red boots were made of dyed leather.  "
           "The making is of high quality and the inside is "
           "a soft red fur.");
   SetMass(20);
   SetValue(95);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetDamagePoints(100);
   // SetProtection(BLUNT,3);
   // SetProtection(SLASH,3);
   // SetProtection(PIERCE,3);
   // SetProtection(COLD,7);
   // SetProtection(HEAT,1);
   SetWear("The boots are soft inside.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(6);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "leather working" : 2,
                  ]) );
   SetProperty("history","These boots used to be the property of Samson, "
               "the Parva Mayor.");
}

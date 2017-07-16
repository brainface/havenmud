#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a bright red shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "shirt","red","bright" }) );
   SetLong("The bright red shirt is made of a soft, smooth "
           "textile.  It is thin, and doesn't offer much "
           "protection, but allows for decency.");
   SetMass(10);
   SetValue(45);
    SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(35);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,1);
   // SetProtection(HEAT,1);
   SetWear("The shirt is a little chill.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","This shirt used to be the property of Samson, "
               "the Parva Mayor.");
}

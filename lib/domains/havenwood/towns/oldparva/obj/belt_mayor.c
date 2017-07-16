#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("belt");
   SetShort("a bright red belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "belt","red","bright" }) );
   SetLong("The belt is bright and red.  It isn't very long, but "
           "was carefully crafted.  Stitched in white are some "
           "simple designs of dragons and unicorns fighting.");
   SetMass(2);
   SetValue(35);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BELT);
   SetDamagePoints(50);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,1);
   // SetProtection(HEAT,1);
   SetWear("The belt is tight.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(1);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","This belt used to be the property of Samson, "
               "the Parva Mayor.");
}

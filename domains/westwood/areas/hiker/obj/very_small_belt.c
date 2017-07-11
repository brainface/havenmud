#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("black leather belt");
   SetShort("a black leather belt");
   SetId( ({ "belt","leather" }) );
   SetAdjectives( ({ "black","leather" }) );
   SetLong("The belt is a strip of leather dyed black.  It is about "
           "half of an inch wide, and a quarter of a centimeter thick.  It would fit "
           "a very small waist.");
   SetValue(5);
   SetMass(5);
   SetArmourClass(ARMOUR_LEATHER);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BELT);
   SetDamagePoints(100);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,4);
   // SetProtection(BLUNT,4);
   // SetProtection(COLD,1);
   // SetProtection(HEAT,1);
   // SetProtection(ACID,1);
   SetMaterial( ({ "leather" }) );
   SetWarmth(2);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
   SetSize(SIZE_VERY_SMALL);
}

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("leather belt");
   SetShort("a leather belt");
   SetId( ({ "belt","strip","leather" }) ); 
   SetAdjectives( ({ "leather" }) );
   SetLong("This strip of leather has a a nice fastener on the end.");
   SetMass(15);
   SetValue(10);
   SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
   SetArmourType(A_BELT);
   SetDamagePoints(275);
   // SetProtection(PIERCE,2);
   // SetProtection(SLASH,3);
   // SetProtection(BLUNT,3);
   // SetProtection(COLD,1);
   // SetProtection(ACID,1);
   // SetProtection(HEAT,1);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "leather working" : 1,
                  ]) );
}

#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hiking boots");
   SetShort("a pair of hiking boots");
   SetId( ({ "boots","boot","pair of boots","pair of hiking boots" }) );
   SetAdjectives( ({ "hiking","well-padded","thick","tough","leather" }) );
   SetLong("The boots are well-padded with thick and tough cloth "
           "and leather having been used to make them.  Padded soles "
           "make up the bottom, and string laces are used to keep them "
           "on one's feet.  The toes appear to be made of steel.");
   SetMass(30);
   SetDamagePoints(650);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetArmourType(A_BOOT);
   SetProperty("multiples",1);
   SetValue(95);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,6);
   // SetProtection(COLD,8);
   // SetProtection(ACID,1);
   // SetProtection(HEAT,1);
   // SetProtection(WATER,1);
   SetMaterial( ({ "textile","leather","metal" }) );
  SetWarmth(8);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "armour smithing" : 2,
                       "textile working" : 2,
                       "leather working" : 2,
                       "metal working" : 1,
                  ]) );
   // Make it so, if "kick" is used, bonus damage.
   SetSize(SIZE_MEDIUM);
}

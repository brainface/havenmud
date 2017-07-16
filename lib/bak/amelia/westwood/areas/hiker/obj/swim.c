#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("wet shorts");
   SetSize(SIZE_MEDIUM);
   SetShort("a pair of wet shorts");
   SetId( ({ "shorts","short" }) );
   SetAdjectives( ({ "pair of","wet" }) );
   SetLong("These green shorts have been soaked all the way through!  "
           "They are pretty thin and floppy too.");
   SetMass(20);
   SetValue(2);
   SetDamagePoints(50);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_PANTS);
   SetProtection(SLASH,1);
   SetProtection(BLUNT,1);
   SetProtection(PIERCE,2);
   SetProtection(COLD,-4);
   SetProtection(HEAT,4);
   SetProtection(ACID,2);
   SetProtection(WATER,-4);
   SetMaterial( ({ "textile" }) );
   SetWarmth(4);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "textile working" : 0,
                       "armour smithing" : 0,
                  ]) );
}

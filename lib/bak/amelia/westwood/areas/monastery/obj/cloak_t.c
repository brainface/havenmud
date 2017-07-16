#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("travelling cloak");
   SetShort("a travelling cloak");
   SetId( ({ "cloak" }) );
   SetAdjectives( ({ "travelling","travelers","traveler" }) );
   SetLong("The cloak is old and well-used, but it seems like it "
           "would keep one warm and safe.");
   SetMass(95);
   SetValue(85);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetDamagePoints(550);
   SetProtection(PIERCE,4);
   SetProtection(SLASH,2);
   SetProtection(BLUNT,2);
   SetProtection(COLD,9);
   SetMaterial( ({ "textile" }) );
  SetWarmth(20);
   SetRepairDifficulty(8);
   SetRepairSkills( ([
                       "textile working" : 2,
                       "armour smithing" : 2,
                  ]) );
   SetSize(SIZE_SMALL);
}

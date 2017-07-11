#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("slippers");
   SetShort("a pair of orange slippers");
   SetId( ({ "slippers" }) );
   SetAdjectives( ({ "orange","pair of" }) );
   SetLong("The orange slippers were made for someone who doesn't "
           "leave home often; they appear well-worn.  They are "
           "orange with a red trim.");
   SetMass(10);
   SetValue(5);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetDamagePoints(15);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,1);
   // SetProtection(HEAT,1);
   SetWear("The slippers were once soft on the inside, but the "
           "softness has been worn away.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(3);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","These slippers used to be the property "
               "of Pons, a Parva storekeeper, or Snop, his twin brother.  They wore them instead "
               "of boots or shoes because it hurt tir feet to "
               "wear boots or shoes.  Much of the town of Parva "
               "laughed at them for wearing slippers, but they felt "
               "most comfortable in ttheym.");
}

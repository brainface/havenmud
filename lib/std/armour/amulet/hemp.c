#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hemp necklace");
   SetShort("a hemp necklace");
   SetId( ({ "hemp","necklace","hemp necklace" }) );
   SetAdjectives( ({ "hemp" }) );
   SetLong("The hemp necklace is just some braided hemp that has been "
           "tied together to form a necklace that would be tight on most people.");
   SetMass(4);
   SetValue(15);
  SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_AMULET);
  SetSize(SIZE_MEDIUM);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(225);
   SetWear("The hemp wraps close to your neck.");
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(23);
   SetRepairSkills( ([
                       "natural working" : 3,
                       "armour smithing" : 1,
                  ]) );
}

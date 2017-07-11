#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a silk shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "silk" }) );
   SetLong("The silk shirt is soft to the touch and smooth "
           "against skin, fur, and scales.  The designer "
           "had great talent.");
   SetMass(8);
   SetArmourType(A_SHIRT);
    SetArmourClass(ARMOUR_CLOTH);
   SetValue(195);
   SetClass(10,9);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(70);
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(13);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
}

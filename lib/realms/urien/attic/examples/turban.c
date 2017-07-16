#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("turban");
   SetId( ({ "dingy" }) );
   SetAdjectives( ({ "old" }) );
   SetShort("an old dingy turban");
   SetLong(
   "This turban appears old and worn from numerous years of use. On the front "
   "of this headwrap is a broken blue bead which has a feather poking out of it "
   "upward. The feather is white but missing most of its body and mostly that "
   "remains is the stem. The outside of this headwrap is made of cloth and it "
   "has a dark brown color to the wrapping."
   );
   SetVendorType(VT_ARMOUR);
   SetMass(40);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetValue(100);
   SetDamagePoints(50);
   SetMaterial( ({ "textile" }) );
   SetArmourType(A_HELMET);
   SetWarmth(2);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "textile working" : 5,
                       "armour smithing" : 5,
                  ]) );
}

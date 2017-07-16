#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>

#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("flannel shirt");
   SetId( ({ "flannel","shirt" }) );
   SetAdjectives( ({ "flannel" }) );
   SetShort("a flannel shirt");
   SetLong("The shirt is light brown in color and looks very warm.");
   SetVendorType(VT_ARMOUR);
   SetMass(30);
   SetValue(90);
   SetDamagePoints(90);
    SetArmourClass(ARMOUR_CLOTH);
   SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_ARMOUR);
   SetMaterial( ({ "textile" }) );
  SetWarmth(20);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "textile working" : 2,
                       "armour smithing" : 2,
                  ]) );
}

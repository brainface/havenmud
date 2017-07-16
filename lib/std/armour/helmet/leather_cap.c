#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("leather cap");
   SetId( ({ "cap" }) );
   SetAdjectives( ({ "leather" }) );
   SetShort("a leather cap");
   SetLong("The thick leather cap is large enough to cover much of ones "
           "ears and neck");
   SetVendorType(VT_ARMOUR);
   SetMass(50);
  SetArmourClass(ARMOUR_LEATHER);

  SetSize(SIZE_MEDIUM);
   SetValue(150);
   SetDamagePoints(250);
   SetArmourType(A_HELMET);
   SetMaterial( ({ "leather" }) );
  SetWarmth(9);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
}

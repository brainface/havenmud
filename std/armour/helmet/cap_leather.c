#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
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
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
   SetValue(150);
   SetDamagePoints(250);
   SetMaterial( ({ "leather" }) );
   SetArmourType(A_HELMET);
  SetWarmth(5);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
}

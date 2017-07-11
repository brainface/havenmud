#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of leather pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","leather" }) );
   SetLong("These are ordinairy leather pants.  They look to be "
           "rather all-purpose.");
   SetMass(15);
   SetArmourType(A_PANTS);
    SetArmourClass(ARMOUR_LEATHER);
   SetValue(55);
   SetClass(10,8);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(150);
   SetMaterial( ({ "leather" }) );
  SetWarmth(20);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "leather working" : 0,
                  ]) );
}


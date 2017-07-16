#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("belt");
   SetShort("a leather belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "leather" }) );
   SetArmourType(A_BELT);
   SetLong("This is a fancy leather belt.  Designs are "
           "stiched into the tough leather.  The buckle "
           "is in the shape of dragon.");
   SetMass(5);
   SetValue(225);
    SetArmourClass(ARMOUR_LEATHER);
   SetClass(10,9);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BELT);
   SetDamagePoints(40);
   SetMaterial( ({ "leather","metal" }) );
  SetWarmth(1);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "metal working" : 0,
                       "leather working" : 0,
                  ]) );
}


#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("belt");
   SetShort("a leather belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "leather" }) );
   SetArmourType(A_BELT);
   SetLong("This is a plain leather belt.  It has a simple "
           "buckle on it.");
   SetMass(2);
   SetValue(5);
    SetArmourClass(ARMOUR_LEATHER);
   SetClass(10,5);
   SetArmourType(A_BELT);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(40);
   SetMaterial( ({ "leather","metal" }) );
  SetWarmth(1);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "metal working" : 0,
                       "leather working" : 0,
                  ]) );
}


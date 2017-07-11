#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a plain shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("This is a plain shirt made of a basic, all-purpose "
           "textile.");
   SetMass(5);
   SetArmourType(A_SHIRT);
    SetArmourClass(ARMOUR_CLOTH);
   SetValue(35);
   SetClass(10,8);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(70);
   SetMaterial( ({ "textile" }) );
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "textile working" : 0,
                  ]) );
}


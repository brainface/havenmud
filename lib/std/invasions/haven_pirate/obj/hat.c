#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hat");
   SetShort("a hat with a feather");
   SetId( ({ "hat","feather" }) );
   SetAdjectives( ({ "hat","with a","feather" }) );
   SetLong("This is a plain hat made of leather with a "
           "bird feather decorating it.");
   SetMass(5);
    SetArmourClass(ARMOUR_CLOTH);
   SetValue(35);
   SetClass(10,9);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(40);
   SetMaterial( ({ "leather","natural" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "natural working" : 0,
                       "leather working" : 0,
                  ]) );
}


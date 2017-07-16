//Illura@Haven
//Nov 2010
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hat");
   SetShort("a plumed tricorne hat");
   SetId( ({ "hat","tricorn", "plumed" }) );
   SetAdjectives( ({ "hat","tricorne", "plumed" }) );
   SetLong("This is a velvet hat with a large feather.");
   SetMass(5);
   SetValue(45);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(300);
   SetMaterial( ({ "leather","natural" }) );
   SetWarmth(5);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
        "natural working" : 1,
        "leather working" : 1,
        ]) );
}

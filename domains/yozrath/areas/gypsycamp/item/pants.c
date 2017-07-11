#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
     armour::create();
     SetKeyName("pants");
     SetShort("bright red pants");
     SetId( ({ "pants" }) );
     SetAdjectives( ({ "bright", "red"}) );
     SetLong("These bright red pants hug the calves right below "
             "the knee and puff out above.");
     SetMass(5);
     SetValue(0);
     SetVendorType(VT_ARMOUR);
     SetArmourType(A_PANTS);
     SetMaterial( ({ "textile" }) );
     SetArmourClass(ARMOUR_CLOTH);
     SetSize(SIZE_MEDIUM);
    SetWarmth(15);
     SetDamagePoints(100);
     SetRepairDifficulty(1);
     SetRepairSkills( ([
       "textile working" : 0,
       ]) );
   }


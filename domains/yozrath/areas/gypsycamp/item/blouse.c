#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
     armour::create();
     SetKeyName("blouse");
     SetShort("a cotton blouse");
     SetId( ({ "blouse" }) );
     SetAdjectives( ({ "cotton"}) );
     SetLong("This light, cotton blouse is the perfect thing for "
             "hot days and nights by keeping the wearer cool.");
     SetMass(5);
     SetValue(0);
     SetVendorType(VT_ARMOUR);
SetSize(SIZE_MEDIUM);
SetArmourClass(ARMOUR_CLOTH);
     SetArmourType(A_SHIRT);
     SetMaterial( ({ "textile" }) );
    SetWarmth(10);
     SetDamagePoints(100);
     SetRepairDifficulty(1);
     SetRepairSkills( ([
       "textile working" : 0,
       ]) );
   }


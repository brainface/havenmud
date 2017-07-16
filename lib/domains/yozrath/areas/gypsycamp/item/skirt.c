#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
     armour::create();
     SetKeyName("skirt");
     SetShort("a long red skirt");
     SetId( ({ "skirt" }) );
     SetAdjectives( ({ "long", "red"}) );
     SetLong("This long red skirt is of thin, lightweight material. "
             "It attaches to the waist with a matching sash.");
     SetMass(5);
     SetValue(0);
     SetVendorType(VT_ARMOUR);
     SetSize(SIZE_MEDIUM);
     SetArmourType(A_PANTS);
   SetArmourClass(ARMOUR_CLOTH);
     SetMaterial( ({ "textile" }) );
    SetWarmth(10);
     SetDamagePoints(100);
     SetRepairDifficulty(1);
     SetRepairSkills( ([
       "textile working" : 0,
       ]) );
   }


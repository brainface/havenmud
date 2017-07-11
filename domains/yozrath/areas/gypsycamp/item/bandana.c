#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
     armour::create();
     SetKeyName("bandana");
     SetShort("a black bandana");
     SetId( ({ "bandana" }) );
     SetAdjectives( ({ "black" }) );
     SetLong("This black bandana is to be worn on the head "
             "to keep the sweat off the brow. It has silver "
             "threads running through it.");
     SetMass(5);
     SetValue(0);
     SetVendorType(VT_ARMOUR);
     SetArmourType(A_HELMET);
     SetMaterial( ({ "textile" }) );
     SetArmourClass(ARMOUR_CLOTH);
     SetSize(SIZE_MEDIUM);
    SetWarmth(3);
     SetDamagePoints(100);
     SetRepairDifficulty(1);
     SetRepairSkills( ([
       "textile working" : 0,
       ]) );
   }


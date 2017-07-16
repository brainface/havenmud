#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
     armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
     SetKeyName("belt");
     SetShort("a spiked black belt");
     SetId( ({ "belt" }) );
     SetAdjectives( ({ "spiked", "black"}) );
     SetLong("This is a spiked black belt.");
     SetMass(5);
     SetValue(2);
     SetWarmth(1);
     SetVendorType(VT_ARMOUR);
     SetArmourType(A_BELT);
     SetDamagePoints(100);
   }

// Amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("ring");
   SetShort("a green scintillating ring");
   SetId( ({ "ring" }) );
   SetAdjectives( ({ "scintillating","green" }) );
   SetLong("The ring is formed of white gold, with a beautiful oak tree crafted "
           "into it.");
   SetArmourType(A_RING);
   SetVendorType(VT_ARMOUR|VT_TREASURE); 
   SetArmourClass(ARMOUR_CHAIN);
   SetMass(0.25);
   SetValue(200);
   SetDamagePoints(200);
   SetMaterial("metal");
   SetSize(SIZE_MEDIUM);
}

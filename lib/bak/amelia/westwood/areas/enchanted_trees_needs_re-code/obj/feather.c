// Amelia@Haven

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
 
inherit LIB_ARMOUR;
 
static void create() {
   armour::create();
   SetKeyName("feather");
   SetId( ({ "feather","white feather" }) );
   SetAdjectives( ({ "white" }) );
   SetShort("a white feather");
   SetLong("A white feather that might look good in someone's hair.");
   SetMass(10);
   SetValue(15);
   SetDamagePoints(200);
   SetProtection(BLUNT,1);
   SetProtection(SLASH,1);
   SetProtection(PIERCE,1);
   SetArmourType(A_HELMET);
   SetMaterial( ({ "natural" }) );
}

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
   SetKeyName("gloves");
   SetShort("a pair of black leather gloves");
   SetId( ({ "gloves","glove","pair" }) );
   SetAdjectives( ({ "pair of","leather","black" }) );
   SetLong("Rough stitching mended these gloves some time in the "
           "past, creating uneven seams on the side of otherwise "
           "well-made black leather gloves.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_GLOVE);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(1);
   SetValue(30);
   SetDamagePoints(350);
   SetProperty("multiples",1);
   SetSize(SIZE_MEDIUM);
}

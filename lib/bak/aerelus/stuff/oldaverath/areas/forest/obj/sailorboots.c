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
   SetKeyName("boots");
   SetShort("a pair of black leather boots");
   SetId( ({ "boots","pair" }) );
   SetAdjectives( ({ "pair of","leather","black" }) );
   SetLong("The polished surface of the leather boots is marred "
           "by minor scuffs and scratches from months of rigorous "
           "wear, though none effect the overall quality of the "
           "boot's protection.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BOOT);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(2);
   SetValue(50);
   SetDamagePoints(400);
   SetProperty("multiples",1);
   SetSize(SIZE_MEDIUM);
}

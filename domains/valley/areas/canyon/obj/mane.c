#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("mane");
   SetShort("a pony mane");
   SetId( ({ "mane","hair" }) );
   SetAdjectives( ({ "pony","shaggy","horse" }) );
   SetLong("The shaggy horse hair that makes up this mane could be "
           "useful for something.");
   SetMass(5);
   SetArmourType(A_HELMET);
   SetArmourClass(ARMOUR_CLOTH);
   SetWear("The horse hair feels out of place on your head.");
   SetValue(5);
   SetVendorType(VT_CLOTHING);
   SetDamagePoints(75);
   SetMaterial( ({ "natural" }) );
   SetWarmth(5);
}


/* Approved by Zaxan on Sat Jan 17 02:39:45 1998. */

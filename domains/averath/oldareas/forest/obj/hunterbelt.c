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
   SetKeyName("belt");
   SetShort("a leather belt");
   SetId( ({ "belt" }) );
   SetAdjectives( ({ "brown","leather" }) );
   SetLong("The clasp of this brown belt is in the shape of a dragon's "
           "head, but has a blocky, unpolished appearance.");
   SetArmourType(A_BELT);
   SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(1);
   SetValue(50);
   SetDamagePoints(450);
   SetSize(SIZE_MEDIUM);
}

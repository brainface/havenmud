// amelia
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("boots");
   SetShort("a pair of tan leather boots");
   SetId( ({ "boots" }) );
   SetAdjectives( ({ "pair of","leather","tan"}) );
   SetLong("The solid boots have a light tan coloration.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_BOOT);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(10);
   SetValue(70);
   SetProperty("multiples",1);
   SetDamagePoints(400);
   SetSize(SIZE_MEDIUM);
}

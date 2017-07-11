#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("blue feather");
   SetShort("a blue feather");
   SetId( ({ "feather" }) );
   SetAdjectives( ({ "blue" }) );
   SetLong("The feather has a very striking blue color to it.");
   SetMass(1);
   SetValue(7);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(77);
   SetMaterial( ({ "natural" }) );
}


/* Approved by Zaxan on Sat Jan 17 02:40:27 1998. */
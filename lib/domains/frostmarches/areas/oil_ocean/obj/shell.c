#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("pretty shell");
   SetShort("a pretty shell");
   SetId( ({ "shell" }) );
   SetAdjectives( ({ "pretty" }) );
   SetLong("Designs color the pretty shell as it swirls around.");
   SetMass(1);
   SetValue(5);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(15);
   SetMaterial( ({ "natural" }) );
}


/* Approved by Zaxan on Sat Jan 17 02:42:18 1998. */


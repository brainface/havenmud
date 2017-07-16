// amelia
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("opal");
   SetShort("an unfinished opal");
   SetId( ({ "opal","gem" }) );
   SetAdjectives( ({ "unfinished" }) );
   SetLong("The opal lacks the smooth surface that makes it truly "
           "beautiful, but still has iridescent coloring.");
   SetMass(2);
   SetValue(300);
   SetVendorType(VT_GEM|VT_TREASURE);
   SetDamagePoints(50);
}

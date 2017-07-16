// Amelia
#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;
 
static void create() {
   ::create();
   SetKeyName("pole");
   SetShort("a fishing pole");
   SetId( ({ "pole"  }) );
   SetAdjectives( ({ "fishing" }) );
   SetLong("The fishing pole is a long, flexible strip of wood, with a "
           "string attached that has a simple metal hook on the end.");
   SetClass(5);
   SetValue(50);
   SetMass(20);
   SetVendorType(VT_TREASURE | VT_FISHING);
   SetStrength(120);
   SetChance(60);
   SetDamagePoints(50);
}

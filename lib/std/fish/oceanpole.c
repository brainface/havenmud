#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
   pole::create();
   SetKeyName("pole");
   SetShort("a deep sea fishing pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "deep" ,"sea" ,"fishing" }) );
   SetLong("This rather large pole is made from a mixture of mithril and "
           "some unknown metal, making the pole extremely strong. The size "
           "of the pole indicates that it was specifically designed for "
           "deep sea fishing.");
   SetClass(5);
   SetValue(10000);
   SetMass(10);
   SetStrength(5000);
   SetVendorType(VT_FISHING);
   SetChance(90);
   SetDamagePoints(900);
   SetMaterial( ({ "mithril", "metal" }) );
}

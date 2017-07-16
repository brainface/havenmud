#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
   pole::create();
   SetKeyName("pole");
   SetShort("a blue fishing pole");
   SetId( ({ "pole","blue pole" }) );
   SetAdjectives( ({ "blue","fishing" }) );
   SetLong("This fishing pole is very odd.  It's hard to tell "
           "exactly what it's doing.  It seems to glow a little.");
   SetClass(5);
   SetValue(1000);
   SetMass(3);
   SetStrength(400);
   SetVendorType(VT_FISHING);
   SetChance(90);
   SetDamagePoints(900);
   SetMaterial( ({ "natural" }) );
   SetRadiantLight(1);
   SetProperty("magic","This fishing pole was blessed by a "
               "enchanter who loved fishing.  It greatly increases "
               "ones' chance of catching fish, and glows slightly.  "
               "It is more difficult to break than normal fishing "
               "poles, too, and was blessed into near weightlessness.");
   SetProperty("history","This fishing pole was made by an enchanter.");
}

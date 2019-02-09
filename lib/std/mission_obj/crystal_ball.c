// crystal ball by whoknows whenknows

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;



static void create() {
   item::create();
   SetKeyName("ball");
   SetShort("a crystal ball");
   SetId( ({ "ball", "crystal ball" }) );
   SetAdjectives( ({ "crystal"}) );
   SetLong(
           "This is a beautiful crystal ball. The center"
           " of the ball is very hazy, but it appears"
           " as though a trained eye might be able"
           " to discern the future from it.");
   SetDamageType(BLUNT);
   SetClass(5);
   SetMass(250);
   SetValue(1000);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(450);
   SetVendorType(VT_TREASURE);
}


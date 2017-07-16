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
   SetLong("This is a beautiful crystal ball. The center"
           " of the ball is very hazy, but it appears"
           " as though a trained eye might be able"
           " to discern the future from it.");
   SetMass(250);
   SetValue(0);
   SetDestroyOnSell(1);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(450);
   SetVendorType(VT_TREASURE);
}

#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
   pole::create();
   SetKeyName("pole");
   SetShort("a green fishing pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "green","fishing" }) );
   SetLong("This fishing pole seems to have been made by an average "
           "quality smithy. Two pieces of thin wire have been "
           "braided for extra durability which run to a small "
           "spool at the end. The leather grip along the fat end "
           "of this linear pole is black and has been moistened "
           "properly. The flexible outside metal has been painted "
           "a dark forest green colour all the way from the grip "
           "to the thin pointy edge.");
   SetClass(5);
   SetValue(1500);
   SetMass(15);
   SetStrength(300);
   SetVendorType(VT_FISHING);
   SetChance(60);
   SetDamagePoints(400);
   SetMaterial( ({ "metal" }) );
}

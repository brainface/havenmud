#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
   pole::create();
   SetKeyName("pole");
   SetShort("a plain fishing pole");
   SetId( ({ "pole" }) );
   SetStrength(90);
   SetDamagePoints(10);
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(5);
   SetAdjectives( ({ "plain","fishing" }) );
   SetLong("This fishing pole is plain and without adornments.  "
           "It looks sufficient for basic fishing, but probably "
           "breaks easily and doesn't improve that much on "
           "bare hands.");
   SetClass(1);
   SetValue(5);
   SetMass(20);
   SetVendorType(VT_FISHING);
   SetChance(5);
   SetStrength(5);
}
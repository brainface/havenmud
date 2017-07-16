// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("painting");
   SetShort("an old painting");
   SetId(({ "painting" }) );
   SetAdjectives( ({ "old" }) );
   SetLong("At the base of the painting, a beautiful maiden lays in an "
           "inch of dark water, a golden halo resting above her brow.  "
           "In the darkness behind, an ominous figure looms threateningly.  "
           "A gilted frame holds the painting, and a pane of glass covers "
           "it in protection.");
   SetMass(40);
   SetValue(200);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(25);
}

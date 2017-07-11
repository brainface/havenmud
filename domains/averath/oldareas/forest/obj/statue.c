// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("statue");
   SetShort("an old statue");
   SetId(({ "statue" }) );
   SetAdjectives( ({ "old" }) );
   SetLong("Formed from a solid, heavy white stone with pale green "
           "marbling, the statue depicts a tsunami curling over a "
           "group of three women.  The women are dancing together, "
           "hands locked, and none of them wear anything except "
           "necklaces.");
   SetMass(100);
   SetValue(300);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(55);
}

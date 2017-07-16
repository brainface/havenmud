// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("abalone");
   SetShort("an iridescent abalone shell");
   SetId(({ "abalone","shell" }) );
   SetAdjectives( ({ "iridescent","abalone" }) );
   SetLong("Miniature rainbows sparkle in the soft, comforting grey color of "
           "the abalone shell. ");
   SetMass(1);
   SetValue(50);
   SetVendorType(VT_TREASURE);
   SetDamagePoints(40);
}

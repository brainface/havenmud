// Amelia
#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("garnet");
   SetShort("a rough garnet");
   SetId( ({ "garnet" }) );
   SetAdjectives( ({ "rough" }) );
   SetLong("The center of the garnet shines with a deep red, almost "
           "as gorgeous as a ruby, but slightly dimmer and paler.  "
           "It is about a 4 centimeters in diameter, and has a "
           "rough shape.");
   SetMass(2);
   SetValue(100);
   SetVendorType(VT_GEM|VT_TREASURE);
   SetDamagePoints(50);
}

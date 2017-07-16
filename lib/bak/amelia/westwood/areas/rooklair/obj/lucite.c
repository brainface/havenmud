#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("lucite");
  SetId( ({ "lucite","crystal" }) );
  SetShort("%^MAGENTA%^BOLD%^a light purple crystal%^RESET%^");
  SetLong("Lucite is a crystal that is hexagonal in "
    "shape and light purple color and is slightly "
    "translucent.  The stone is uncut.");
  SetAdjectives( ({"small","lucite","crystal","purple"}) );
  SetMass(5);
  SetValue(3500);
  SetMaterial("natural");
  SetVendorType(VT_TREASURE);
}

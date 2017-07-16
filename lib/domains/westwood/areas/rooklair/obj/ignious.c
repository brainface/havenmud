#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("ignious");
  SetId( ({ "ignious","gem" }) );
  SetShort("a dark green gem");
  SetLong("Ignious is a semi-precious gemstone that is "
    "a dark green color and highly translucent.  The "
    "stone is cut into a oval pattern with large cuts.");
  SetAdjectives( ({"small","igniouos","gem","dark","green"}) );
  SetMass(5);
  SetValue(2000);
  SetMaterial("natural");
  SetVendorType(VT_TREASURE);
}

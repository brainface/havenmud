#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("pouch");
  SetId( ({ "argonite","powder","pouch" }) );
  SetShort("a small pouch");
  SetLong("This is a small leather pouch.  Inside of it "
    "is a small amount of argonite powder, which is "
    "exceptionally rare.  The powder is a soft white "
    "in colour.");
  SetAdjectives( ({"small","leather"}) );
  SetMass(7);
  SetValue(5500);
  SetMaterial("natural");
  SetVendorType(VT_TREASURE);
}

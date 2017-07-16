
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("teeth");
  SetShort("sharp teeth");
  SetId( ({"teeth"}) );
  SetAdjectives("sharp");  
  SetLong("These are some sharp teeth from a wolf.");
  SetValue(600);
  SetMass(10);
  SetVendorType(VT_TREASURE);
 }

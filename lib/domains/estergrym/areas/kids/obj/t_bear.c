//Samah@Haven
//20040911
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetId( ({ "bear" }) );
  SetAdjectives( ({ 
     "torn",
      "soaked",
      "tattered",
      "teddy" 
  }) );
  SetKeyName("teddy bear");
  SetShort("a torn teddy bear");
  SetLong(
     "This pathetic bear is all but completely destroyed.  "
     "Its head hangs by a few dangling threads, and stuffing "
     "flows freely from its partially opened neck."
  );
  SetDamagePoints(4);
  SetValue(10);
  SetMass(5);
  SetMaterial( ({ "textile" }) );
  SetVendorType(VT_TREASURE);
}

/** Approved by Laoise at Sat Sep 11 20:28:03 2004. **/
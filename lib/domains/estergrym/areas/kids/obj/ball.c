//Samah@Haven
//20040911
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a small ball");
  SetLong(
     "The small red ball is completely flat and appears to be worn down "
     "from constant use.  Its surface is marred by many "
     "scratches and tears."
  );
  SetId( ({ "ball" }) );
  SetAdjectives( ({ 
     "small",
     "red" 
  }) );
  SetDamagePoints(4);
  SetValue(10);
  SetKeyName("ball");
  SetMass(10);
  SetMaterial( ({ "leather" }) );
  SetVendorType(VT_TREASURE);
}

/** Approved by Laoise at Sat Sep 11 20:27:51 2004. **/
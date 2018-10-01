//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
inherit LIB_CHAIR;

static void create() {
  ::create();
  SetKeyName("chair");
  SetId( ({ "chair" }) );
  SetAdjectives( ({ "wooden", "simple" }) );
  SetShort("a wooden chair");
  SetLong( 
    "This a simple wooden chair. "
    "A person could 'sit down in chair' to occupy it."
  );
  SetClass(1);
  SetMass(30);
  SetValue(0);
  SetMaxSitters(1);
  SetVendorType(VT_TREASURE);
  }

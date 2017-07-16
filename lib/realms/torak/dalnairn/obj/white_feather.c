//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("feather");
  SetId( ({ "feather" }) );
  SetAdjectives( ({ "long", "white" }) );
  SetShort("a long white feather");
  SetLong( "This long white feather is tipped with black." );
  SetClass(1);
  SetMass(5);
  SetValue(10);
  SetVendorType(VT_TREASURE);
  }

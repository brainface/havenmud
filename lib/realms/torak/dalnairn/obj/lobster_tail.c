//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("tail");
  SetId( ({ "tail" }) );
  SetAdjectives( ({ "blue", "lobster" }) );
  SetShort("a blue lobster tail");
  SetLong( "This a tail from a blue lobster." );
  SetClass(1);
  SetMass(10);
  SetValue(50);
  SetVendorType(VT_TREASURE);
  }

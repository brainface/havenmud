//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("tusk");
  SetId( ({ "tusk" }) );
  SetAdjectives( ({ "short", "ivory" }) );
  SetShort("a short ivory tusk");
  SetLong( "This a short ivory tusk from a wild boar." );
  SetClass(1);
  SetMass(25);
  SetValue(75);
  SetVendorType(VT_TREASURE);
  }

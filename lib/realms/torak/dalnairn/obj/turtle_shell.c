//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("shell");
  SetId( ({ "shell" }) );
  SetAdjectives( ({ "turtle" }) );
  SetShort("a turtle shell");
  SetLong( "This a shell from a small green turtle." );
  SetClass(1);
  SetMass(5);
  SetValue(25);
  SetVendorType(VT_TREASURE);
  }

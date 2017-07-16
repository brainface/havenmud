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
  SetAdjectives( ({ "short", "green" }) );
  SetShort("a short green feather");
  SetLong( "This short green feather is tappered and shiny." );
  SetClass(1);
  SetMass(5);
  SetValue(20);
  SetVendorType(VT_TREASURE);
  }

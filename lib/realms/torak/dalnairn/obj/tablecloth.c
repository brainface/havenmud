//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// Taken from a google search for grave jokes
// 

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetId( ({
    "tablecloth", "cloth"
  }) );
  SetKeyName("tablecloth");
  SetAdjectives( ({ 
    "checkered" 
  }) );
  SetShort("a checkered tablecloth");
  SetLong(
    "A red and white checkered tablecloth. "
  );
  SetMaterials( ({"textile"}) );
  SetClass(1);
  SetMass(1);
  SetValue(30);
  SetVendorType(VT_TREASURE);
}

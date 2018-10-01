//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_BURN;

static void create() {
  ::create();
  SetKeyName("candle");
  SetShort("a white candle");
  SetLong(
    "This is a white candle made from wax. "
    "There is a braided cotton wick at its top. "
    "Perhaps you should <light> it? "
  );
  SetId( ({ 
    "candle", "wick" 
  }) );
  SetAdjectives( ({ 
    "white", "wax", "braided", "cotton" 
  }) );
  SetFlickerString(
    "flickers slightly"
  );
  SetMaxFuel(100);
  SetValue(20);
  SetMaterials( ({ 
    "natural" 
  }) );
  SetRadiantLight(5);
  SetHeat(1);
  SetMass(3);
  SetDamagePoints(25);
  SetVendorType(VT_LIGHT);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
}

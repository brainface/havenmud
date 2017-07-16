


#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_BURN;
inherit LIB_SMELL;

static void create() {
   ::create();
   SetKeyName("white candle");
   SetShort("a white candle");
   SetId( ({ "candle" }) );
   SetAdjectives( ({ "white" }) );
   SetLong("Rivlets of wax have dribbled down the side of the " 
           "white candle.");
   SetFlickerString("flickers");
   SetMass(3);
   SetValue(10);
   SetVendorType(VT_LIGHT);
   SetRadiantLight(5);
   SetMaxFuel(500);
   SetHeat(5);
   SetDamagePoints(20);
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
   SetMaterial( ({ "natural" }) );
   SetSmell("Vanilla scents drift out of the candle, as well as "
            "smokey and burnt smells.");
}

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_BURN;

static void create() {
  ::create();
  SetKeyName("lamp");
  SetShort("an ordinary lamp");
  SetLong("This brass lamp appears rather worn and overall ordinary. It refuses "
    "to release any djinn not matter what abuse you apply to it. However, the "
    "resevoir may still hold some oil. Perhaps you should <light> it?");
  SetId( ({ "lamp" }) );
  SetAdjectives( ({ "ordinary" }) );
  SetFlickerString("flickers slightly");
  SetMaxFuel(400);
  SetValue(10);
  SetMaterials( ({ "metal" }) );
  SetRadiantLight(30);
  SetHeat(5);
  SetMass(10);
  SetDamagePoints(400);
  SetVendorType(VT_LIGHT);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
}


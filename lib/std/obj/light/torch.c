#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_BURN;

static void create() {
  ::create();
  SetKeyName("torch");
  SetShort("a wooden torch");
  SetLong("This is a wooden torch. Perhaps you should <light> it?");
  SetId( ({ "torch" }) );
  SetAdjectives( ({ "wooden" }) );
  SetFlickerString("flickers slightly");
  SetMaxFuel(200);
  SetValue(0);
  SetMaterials( ({ "wood" }) );
  SetRadiantLight(30);
  SetHeat(20);
  SetMass(10);
  SetDamagePoints(400);
  SetVendorType(VT_LIGHT);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
}


#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_BURN;

static void create() {
  ::create();
  SetKeyName("torch");
  SetShort("a darkfire torch");
  SetLong(
    "Something oily and stringy to an unfortunate extent coats "
    "the head of this torch. Perhaps you should <light> it?");
  SetId( ({ "torch" }) );
  SetAdjectives( ({ "darkfire" }) );
  SetFlickerString("flickers darkly");
  SetMaxFuel(200);
  SetValue(10);
  SetMaterials( ({ "wood" }) );
  SetRadiantLight(-30);
  SetHeat(20);
  SetMass(10);
  SetDamagePoints(400);
  SetVendorType(VT_LIGHT);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
}


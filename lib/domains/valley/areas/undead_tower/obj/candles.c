///     Created by Severen      ///
///       New Years!!!!!        ///
///         candles.c           ///

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../defs.h"

inherit LIB_BURN;

static void create() {
    ::create();
    SetKeyName("candelabra");
    SetId( ({ "candles", "candelabra" }) );
    SetShort("an ornate candelabra");
    SetAdjectives( ({ "ornate" }) );
    SetLong(
      "A beautiful ornate candelabra stands here. It is made "
      "of steel and is very sturdy. Black candles rest in its six openings "
      "on its top. The elaborate designs on it depict lilies and ivy."
      );
    SetRadiantLight(20);
    SetHeat(5);
    SetMass(100);
    SetValue(200);
    SetClass(10);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
    SetFlickerString("flickers randomly");
    SetMaxFuel(200);
    SetVendorType(VT_LIGHT);
}

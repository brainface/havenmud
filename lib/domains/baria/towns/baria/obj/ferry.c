#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("outrigger");
  SetLimit(3);
  SetShort("a small native outrigger");
  SetId( ({ "ship", "outrigger", }) );
  SetAdjectives( ({ "small", "native" }) );
  SetLong(
    "This small outrigger is big enough for only a few passengers and 1 person to captain it."
    );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(100000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(50000);
  SetWeaponSystem(0);
  SetCaptain("native ferryboatman");
  SetSensorSuite(VSE_LOCAL);
}

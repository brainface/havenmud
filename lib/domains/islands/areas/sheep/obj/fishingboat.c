#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("fishing boat");
  SetLimit(1);
  SetShort("a small fishing boat");
  SetId( ({ "boat",  }) );
  SetAdjectives( ({ "small", "fishing" }) );
  SetLong(
    "This small fishing boat is big enough for only a few passengers and 1 person to captain it."
    );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(50000);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(500);
  SetWeaponSystem(0);
  SetSensorSuite(VSE_LOCAL);
}

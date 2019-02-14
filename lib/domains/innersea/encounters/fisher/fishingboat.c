#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("fishing boat");
  SetLimit(5);
  SetShort("a small fishing boat");
  SetId( ({ "ship", "boat" }) );
  SetAdjectives( ({ "small", "fishing" }) );
  SetLong(
    "This small fishing boat belongs to a local fisherman. "
    "It is small and not likely to be capable of much."
  );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(20000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(50);
  SetWeaponSystem(0);
  SetSensorSuite(VSE_WIDE);
  SetCaptain("fisherman");
}

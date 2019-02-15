#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("yacht");
  SetLimit(5);
  SetShort("a small pleasure yacht");
  SetId( ({ "ship", "yacht" }) );
  SetAdjectives( ({ "small", "pleasure" }) );
  SetLong(
    "This small yacht seems to belong to a local merchant whose wealth exceeds his "
    "intelligence. It is small and not likely to be capable of much."
  );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(20000);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(250);
  SetWeaponSystem(0);
  SetSensorSuite(VSE_WIDE);
}

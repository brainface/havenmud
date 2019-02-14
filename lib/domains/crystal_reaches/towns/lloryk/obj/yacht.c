#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("fishing skiff");
  SetLimit(5);
  SetShort("a halfling fishing skiff");
  SetId( ({ "ship", "skiff" }) );
  SetAdjectives( ({ "halfling", "fishing" }) );
  SetLong(
    "This small skiff seems to be used by the Shire fisherman "
    "for basic fishing needs. It is small and not likely to be capable of much."
  );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(20000);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(250);
  SetWeaponSystem(0);
  SetSensorSuite(VSE_WIDE);
}

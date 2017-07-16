#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("skiff");
  SetLimit(1);
  SetShort("a shallow-bottomed skiff");
  SetId( ({ "ship", "ferry", "skiff" }) );
  SetAdjectives( ({ "shallow", "bottomed" }) );
  SetLong("This small skiff belongs to Nekhonkh the Ferryman, "
    "and he keeps it in shipshape condition.");
  SetVehicleSize(VS_CRUISER);
  SetDamagePoints(1000000);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(50000);
  SetWeaponSystem(VW_SMALL);
  SetCaptain("nekhonkh");
  SetSensorSuite(VSE_WIDE);
}

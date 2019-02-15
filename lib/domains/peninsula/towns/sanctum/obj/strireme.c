#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("Sanctum Trireme");
  SetShort("a Sanctum Trireme");
  SetId( ({ "ship", "trireme" }) );
  SetAdjectives( ({ "sanctum" }) );
  SetLong("This large Galley is unique to Sanctum in design. Though it may not "
          "provide the speed and firepower of a dreadnaught classed ship "
          "this is one of the deadliest ships in its category.");
  SetDamagePoints(8000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetShipStores(2000);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
}

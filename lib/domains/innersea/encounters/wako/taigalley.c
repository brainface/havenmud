#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("slave galley");
  SetShort("a Tai slave galley");
  SetId( ({ "galley", "ship" }) );
  SetAdjectives( ({ "tai", "slave" }) );
  SetLong(
    "This galley wallows with a shallow draft.  While not made for deep-sea "
    "exploration, the occasional captain has been known to sail too far. The "
    "galley has both sails and oars."
    );
  SetDamagePoints(400000);
  SetVehicleSize(VS_GALLEY);
  SetDriveSystem(VM_DEEP);
  SetShipStores(400);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
  SetCaptain("wako captain");
}

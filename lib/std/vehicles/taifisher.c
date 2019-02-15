#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("fishing boat");
  SetShort("a Tai fishing boat");
  SetId( ({ "boat", "ship" }) );
  SetAdjectives( ({ "tai", "fishing" }) );
  SetLong(
    "This small boat is obviously a peasant ship. It is not made for deep-sea "
    "exploration, the occasional captain has been known to sail too far. The "
    "galley has both sails and oars."
    );
  SetDamagePoints(40000);
  SetVehicleSize(VS_YACHT);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(50);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
}

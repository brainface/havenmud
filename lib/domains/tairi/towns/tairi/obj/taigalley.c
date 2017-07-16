#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("servicable galley");
  SetShort("a servicable Tai galley");
  SetId( ({ "galley", "ship" }) );
  SetAdjectives( ({ "tai", "servicable" }) );
  SetLong(
    "This galley wallows with a shallow draft.  While not made for deep-sea "
    "exploration, the occasional captain has been known to sail too far. The "
    "galley has both sails and oars. This ship is older, but still in sailing condition."
    );
  SetDamagePoints(100000);
  SetVehicleSize(VS_GALLEY);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(400);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
}

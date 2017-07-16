#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("ferry");
  SetLimit(1);
  SetShort("a huge wooden ferry");
  SetId( ({ "ship", "ferry" }) );
  SetAdjectives( ({ "wooden", "huge" }) );
  SetLong("This huge ship is a ferry that travels between Haven Town and Averath Island. "
          "It is slow, but free of charge.");
  SetVehicleSize(VS_GALLEY);
  SetDamagePoints(1000000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(50000);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
  SetCaptain("ferry captain");
}

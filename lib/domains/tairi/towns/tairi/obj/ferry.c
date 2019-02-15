#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("ferry");
  SetLimit(3);
  SetShort("a lumbering wooden ferry");
  SetId( ({ "ship", "ferry" }) );
  SetAdjectives( ({ "wooden", "lumbering" }) );
  SetLong("This huge ship is a ferry that travels between Tairi and Parva. "
          "It is slow, but free of charge.");
  SetVehicleSize(VS_GALLEY);
  SetDamagePoints(500000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(50000);
  SetWeaponSystem(VW_MEDIUM);
  SetCaptain("ferry captain");
  SetSensorSuite(VSE_WIDE);
}

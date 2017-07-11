#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("ferry");
  SetLimit(3);
  SetShort("a lumbering wooden ferry");
  SetId( ({ "ship", "ferry" }) );
  SetAdjectives( ({ "wooden", "lumbering" }) );
  SetLong("This huge ship is a ferry that travels between Tairi and Parva. "
          "It is slow, but free of charge.");
  SetVehicleSize(VS_CRUISER);
  SetDamagePoints(1000000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(50000);
  SetWeaponSystem(VW_SMALL);
  SetCaptain("ferry captain");
  SetSensorSuite(VSE_WIDE);
}

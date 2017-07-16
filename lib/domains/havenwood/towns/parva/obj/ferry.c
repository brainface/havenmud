#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("ferry");
  SetLimit(1);
  SetShort("a huge wooden charter ferry");
  SetId( ({ "ship", "ferry" }) );
  SetAdjectives( ({ "wooden", "huge", "charter" }) );
  SetLong("This huge ship is a ferry that travels between various places on Kailie.\n"
          "It can be hired to travel to different islands.");
  SetVehicleSize(VS_GALLEY);
  SetDamagePoints(1000000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(50000);
  SetWeaponSystem(VW_SMALL);
  SetCaptain("charter captain");
  SetSensorSuite(VSE_WIDE);
}

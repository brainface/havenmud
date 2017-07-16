#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("caravel");
  SetShort("a dark-elven caravel");
  SetId( ({ "ship",  "caravel" }) );
  SetAdjectives( ({ "dark", "elven" }) );
  SetLong("This is a Elven Caravel, a sleek killing machine of the deadliest variety.");
  SetDamagePoints(400000);
  SetVehicleSize(VS_GALLEY);
  SetDriveSystem(VM_DEEP);
  SetShipStores(250);
  SetWeaponSystem(VW_MEDIUM);
  SetSensorSuite(VSE_WIDE);
}


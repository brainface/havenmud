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
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetShipStores(250);
  SetWeaponSystem(VW_HUGE);
  SetSensorSuite(VSE_WIDE);
}

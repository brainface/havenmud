#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("caravel");
  SetShort("an elven caravel");
  SetId( ({ "ship", "craft", "caravel" }) );
  SetAdjectives( ({ "elven" }) );
  SetLong("This is a Elven Caravel, a sleek killing machine of the "
          "deadliest variety.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetShipStores(2500);
  SetWeaponSystem(VW_HUGE);
  SetSensorSuite(VSE_WIDE);
}

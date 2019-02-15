#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("warbird");
  SetShort("an elven warbird");
  SetId( ({ "ship", "craft", "warbird" }) );
  SetAdjectives( ({ "elven" }) );
  SetLong("This is a Elven Warbird, a sleek killing machine of the "
          "deadliest variety.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(200);
  SetWeaponSystem(VW_HUGE);
  SetShieldSystem(VSH_MEDIUM);
}

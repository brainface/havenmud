// sloop-da-whoop
// mahkefel 2012--cheap copy of dark elf caravel
#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("sloop");
  SetShort("an elven sloop");
  SetId( ({ "ship",  "sloop" }) );
  SetAdjectives( ({ "elven" }) );
  SetLong("This is an elven sloop, a small, single-masted sailing ship "
    "designed for speed and manueverability and capable of being manned "
    "by only a few skilled crew. A large ballista dominates the aft of the ship, "
    "and the brilliant white sail sports the Kylin scales and dragon.");
  SetDamagePoints(400000);
  SetVehicleSize(VS_GALLEY);
  SetDriveSystem(VM_DEEP);
  SetShipStores(250);
  SetWeaponSystem(VW_MEDIUM);
  SetSensorSuite(VSE_WIDE);
}


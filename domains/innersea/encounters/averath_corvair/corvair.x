#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("corvair");
  SetShort("an averan corvair");
  SetId( ({ "ship", "craft", "corvair" }) );
  SetAdjectives( ({ "corvair" }) );
  SetLong("This is an averan corvair, a small two masted ship outfitted for "
    "speed and manueverability. A large ballista is mounted echelon style on "
    "the port bow and starboard stern to maximize forward firepower. Above the "
    "masts fly the colors of the Duuk of Averath.");
  SetDamagePoints(400000);
  SetVehicleSize(VS_GALLEY);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(500);
  SetWeaponSystem(VW_MEDIUM);
}

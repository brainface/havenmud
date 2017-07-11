#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("elven warship");
  SetShort("an elven warship");
  SetId( ({ "ship", "warship" }) );
  SetAdjectives( ({ "merchant" }) );
  SetLong("This heavily armed dreadnaught flies a kylin flag, it is an elven "
          "warship, feared by those who do not see the light that is Kylin. "
          "The size of the ship and its weapons show just how well this ship "
          "can and will defend itself.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(400);
  SetWeaponSystem(VW_DEVASTATING);
  SetShieldSystem(VSH_LARGE);
}

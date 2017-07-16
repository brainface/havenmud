#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("warship");
  SetShort("a goden warship");
  SetId( ({ "ship", "craft", "warship" }) );
  SetAdjectives( ({ "goden" }) );
  SetLong("This is a goden Warship, a sleek killing machine of the "
          "deadliest variety.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(400);
  SetWeaponSystem(VW_HUGE);
  SetShieldSystem(VSH_MEDIUM);
  SetPrizeBonus(4);
}

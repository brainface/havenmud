
#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("galleon");
  SetShort("a parvan galleon");
  SetId( ({ "galleon", "ship" }) );
  SetAdjectives( ({ "parvan" }) );
  SetLong(
    "This is a parvan galleon, a three masted descendant of the caravel "
    "that compromises manueverability for cargo and armament. Ballista "
    "bolts poke out dozens of holes in the hull of the ship. "
  );
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(4000);
  SetWeaponSystem(VW_HUGE);
  SetShieldSystem(VSH_MEDIUM);
  SetPrizeBonus(4);
  SetCaptain("sea witch");
}


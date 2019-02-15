#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("icebreaker");
  SetLimit(5);
  SetShort("an ironclad icebreaker");
  SetId( ({ "ship", "icebreaker", "ironclad" }) );
  SetAdjectives( ({ "ironclad" }) );
  SetLong(
    "The three masted sailing ship has been reinforced with steel plating "
    "along the bow and underside to protect it from ice. The violence of its "
    "wake indicates the prescence of a paddlewheel for propulsion through the "
    "thickest of ice."
  );
  SetBridgeDescription(
    "The bridge of the icebreaker is covered and insulated from the frigid "
    "arctic temperature outside. Two radiators to the port and starboard ward of "
    "cold and prevent ice from forming on the glass windows."
  );
  SetVehicleSize(VS_CRUISER);
  SetDamagePoints(800000);
  SetDriveSystem(VM_DEEP);
  SetShipStores(20000);
  SetWeaponSystem(VW_HUGE);
  SetSensorSuite(VSE_WIDE);
  SetCaptain("explorer");
}


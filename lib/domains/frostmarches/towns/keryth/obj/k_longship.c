#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("longship");
  SetShort("a goden longship");
  SetId( ({ "ship", "longship" }) );
  SetAdjectives( ({ "goden" }) );
  SetLong("This is a Goden longship, a sleek killing machine of the "
          "deadliest variety.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetShipStores(20000);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
  SetCaptain("viking captain");
}

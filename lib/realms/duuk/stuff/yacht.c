#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("yacht");
  SetCaptain("ai captain");
  SetCrystals(1000);
  SetShort("a small pleasure yacht");
  SetId( ({ "ship", "yacht" }) );
  SetAdjectives( ({ "small", "pleasure" }) );
  SetLong("This small yacht is obviously designed for coastal use only and not for deep sea sailing.");
  SetDamagePoints(100000);
  SetVehicleSize(VS_YACHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
}

#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("spiderdog");
  SetShort("a large spiderdog");
  SetId( ({ "spiderdog" }) );
  SetAdjectives( ({ "large" }) );
  SetLong(
    "This large german shepherd has a beautiful and "
    "full coat of hair with white, brown and black tones. "
    "Someone made this dog a spider halloween outfit and "
    "he just loves it! A saddle has been strapped to his "
    "back for easy riding."
  );
  SetDamagePoints(1500000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(50000);
  SetWeaponSystem(VW_DEVASTATING);
  SetShieldSystem(VSH_LARGE);
}

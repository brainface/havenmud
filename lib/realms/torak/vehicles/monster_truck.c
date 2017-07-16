#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("truck");
  SetShort("a gigantic blue monster truck");
  SetId( ({ "truck" }) );
  SetAdjectives( ({ "monster", "gigantic", "blue" }) );
  SetLong(
    "This is a giant blue monster truck suitable for crushing all things "
    "in its path. The gigantic wheels are so huge that it is capable "
    "of floating and driving in water. Both the front and back wheels "
    "are capable of independent steering so even this immense beast may turn on a "
    "dime. A long rope ladder is curled and bound tight to the driver's door for "
    "exiting in case of disaster. The bed of the truck has been "
    "converted to carry rows of gun turrets. The frame has been "
    "reinforced and the outer skin of the truck has been fitted with "
    "durable armour and painted a sky blue."
  );
  SetDamagePoints(1500000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(50000);
  SetWeaponSystem(VW_DEVASTATING);
  SetShieldSystem(VSH_LARGE);
  SetBridgeDescription(
    "The inner cab of this monster truck is beautiful and panneled in "
    "cherry red stained and sealed oak. The seats are white leather "
    "and stuffed with angel feathers. A shotgun rack hangs over the seats "
    "and dixie cup holders line the doors and the spot between seats. "
    "Various informative circles line the dashboard giving the driver "
    "any and all critical information. "
  );
}

// A nice crappy canoe! Seats two (for you and your partner)
// For Platypus Bay
// Urien@Haven 06JUL08

#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("canoe");
  SetLimit(2);
  SetShort("a small wooden canoe");
  SetId( ({ "canoe", "boat" }) );
  SetAdjectives( ({ "small", "wooden" }) );
  SetLong(
    "This small canoe is made of a fine oak wood. It has a nice strong "
    "hull and is braced by horizontal pieces of wood along the bow. The "
    "inside has two thick planks which seats only two. Sturdy oars are "
    "bolted to the sides to sail in the desired direction."
  );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(10000);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(250);
  SetWeaponSystem(0);
  SetSensorSuite(VSE_WIDE);
}


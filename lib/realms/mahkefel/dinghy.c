#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("dinghy");
  SetShort("a leaky dinghy");
  SetId( ({ "dinghy" }) );
  SetAdjectives( ({ "leaky" }) );
  SetLong("A tiny single-sailed boat that should never be on these waters, as "
    "it's more than two feet deep.");
  SetBridgeDescription("This miserable pile of rotten lumber and misplaced "
    "hope might get one to shore if they prayed hard enough. That rotten sail "
    "fluttered wanly in the wind might be an impediment, though.");
  SetDamagePoints(50000);
  SetVehicleSize(VS_YACHT);
  SetDriveSystem(VM_DEEP);
  SetShipStores(250);
  //SetWeaponSystem(VW_MEDIUM);
  SetSensorSuite(VSE_WIDE);
}


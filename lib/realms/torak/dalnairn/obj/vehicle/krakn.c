//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("krakn");
  SetShort("teh mitey krakn");
  SetId( ({ "krakn", "dreadnaught" }) );
  SetAdjectives( ({ "teh", "mitey" }) );
  SetLong(
    "This immense dreadnaught has been fitted with patches "
    "of treated animal skins, bones, fur and sinew in a "
    "ridiculous attempt to transform it into a sea monster. "
  );
  SetUnique(1);
  SetLimit(1);
  SetDamagePoints(900000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetShipStores(5000);
  SetWeaponSystem(VW_HUGE);
  SetCaptain("gellekros");
}

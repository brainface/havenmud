// slave gallon
#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("galleon");
  SetShort("a gnollish slave galleon");
  SetId( ({ "ship",  "slave", "galleon" }) );
  SetAdjectives( ({ "gnollish","slave" }) );
  SetLong("This is a Gnollish slave galleon, a large, cumbersome ship "
    "outfitted with an arsenal of catapults and equipped with a large hold "
    "for transporting elven slaves captured on Kailie. It was likely "
    "manufactured in Karak with a sizeable portion of the Pharoah's "
    "funds.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetShipStores(1000);
  SetWeaponSystem(VW_HUGE);
  SetSensorSuite(VSE_WIDE);
  SetPrizeBonus(8);
}


#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("merchant ship");
  SetShort("a merchant ship");
  SetId( ({ "ship", "craft" }) );
  SetAdjectives( ({ "merchant" }) );
  SetLong("This heavily armed and shielded ship is a merchant ship. It carries "
          "goods between various islands on the sea. It can easily defend itself "
          "as well as any warship.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(10000);
  SetWeaponSystem(VW_DEVASTATING);
  SetShieldSystem(VSH_LARGE);
  SetPrizeBonus(8);
}


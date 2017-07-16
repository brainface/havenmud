#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("canoe");
  SetLimit(5);
  SetShort("a birchbark canoe");
  SetId( ({ "ship", "canoe" }) );
  SetAdjectives( ({ "birchbark", "birch", "bark" }) );
  SetLong(
    "This shallow drafted canoe is made of thin birchbark. "
    "The lightweight construction allows it to be easily rowed "
    "or propelled by the small triangular sail. It is easily "
    "large enough to carry a dozen lizardman warriors. A large "
    "crossbow mounted on the thwart might deter a lighter craft."
  );
  SetVehicleSize(VS_YACHT);
  SetDamagePoints(20000);
  SetDriveSystem(VM_COASTAL);
  SetShipStores(100);
  SetWeaponSystem(VW_SMALL);
  SetSensorSuite(VSE_WIDE);
  SetCaptain("fisherman");
}


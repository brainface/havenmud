#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("ram");
  SetShort("a Dodge Ram 1500");
  SetId( ({ "ram", "dodge" }) );
  SetAdjectives( ({ "green" }) );
  SetLong("This is a 1995 Dodge Ram 1500 extended-cab, short-bed. "
          "It has a 5.9L Magnum V8, with an automatic transmission. "
          "The exterior is in perfect condition with splashes of mud "
          "all over the sides and hood. The only place you can see "
          "cleanly is where the windshield wipers clear the windshield. "
          "The truck has a 5.5 inch lift kit with 35-10.5 r16 BFGoodrich "
          "TA/MT mud terrain tires.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetShipStores(25000000);
  SetOwner("tassadar");
  SetCaptain("tassadar");
}

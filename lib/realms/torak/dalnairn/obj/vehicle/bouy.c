//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("bouy");
  SetId( ({ "bouy", "chain" }) );
  SetAdjectives( ({ 
    "yellow", "spherical" 
  }) );
  SetShort("a spherical yellow bouy" );
  SetLong( 
    "This spherical bouy is made from the treated "
    "hides of patchwork animal skin and filled with air. "
    "The surface has been painted a bright yellow. "
    "A long mithril chain "
    "acts as mooring connecting the bouy to the sand. "
  );
  SetDamagePoints(5000);
  SetVehicleSize(VS_YACHT);
  SetSensorSuite(VSE_LOCAL);
  SetShipStores(0);
  SetBridgeDescription(
    "Stradling the surface of a spherical yellow bouy. "
  );
}

// disable pirating
mixed CanPirate(object who) {
  return 0;
}

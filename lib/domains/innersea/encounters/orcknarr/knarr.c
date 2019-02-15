#include <lib.h>       
#include <vehicle.h>   
inherit LIB_SHIP;   

static void create() {
  ::create();
  SetKeyName("orcish knarr");
  SetShort("an orcish knarr");
  SetId( ({ "cruiser", "knarr", "ship" }) );
  SetAdjectives( ({ "orcish" }) );
  SetLong(
    "This is an orcish knarr, a floating shrine to the madness that "
    "is saahagoth. Heavy ballista sprout from the the port and starboard "
    "sides, and a wicked iron ramming spur covers the bow. A pair of masts "
    "support simple square sails, painted with a blood-red skull and "
    "crossbones."
  );
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(40000);
  SetWeaponSystem(VW_MEDIUM);
  SetShieldSystem(VSH_MEDIUM);
  SetPrizeBonus(16);
  SetBridgeDescription(
    "Skulls of the reavers victims hang from the masts and uneaten gore "
    "and bones lie scattered on the deck. The ballistae, however, appear "
    "to be in clean working order."
  );
  SetCaptain("saahagoth shaman");
}

#include <lib.h>       
#include <vehicle.h>   
inherit LIB_VEHICLE;   

static void create() {
  ::create();
  SetKeyName("dark-elven marauder");
  SetShort("a dark-elven marauder");
  SetId( ({ "dreadnaught", "marauder", "ship" }) );
  SetAdjectives( ({ "dark-elven", "elven" }) );
  SetLong(
    "A looming shadow in the persistent fog that engulfs it, this dark-elven "
    "marauder could be mistaken for a giant sea monster. It's body carved like "
    "scales and enormous figurehead shaped like a fearsome dragon with "
    "a sharp forked tongue, do nothing to allay the sense of terror instilled "
    "in small children when hearing tales of this vicious dreadnaught slicing "
    "through the seas."
  SetDamagePoints(800000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(40000);
  SetWeaponSystem(VW_MEDIUM);
  SetShieldSystem(VSH_MEDIUM);
  SetPrizeBonus(16);
  SetBridgeDescription(
    "An uneasy fog masks the deck, its mast seeming to rise out of nothing and "
    "pierce the sky with blood red banners. " 
  );
  SetCaptain("saahagoth shaman");
}

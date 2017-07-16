// elemental galleon
// high level endless sea encounter
//
#include <lib.h>
#include <vehicle.h>
inherit LIB_VEHICLE;

static void create() {
  ::create();
  SetKeyName("galleon");
  SetShort("a coral galleon");
  SetId( ({ "ship", "craft", "galleon" }) );
  SetAdjectives( ({ "coral" }) );
  SetLong("The ship sailing before you looks like nothing made by the hand "
    "of man. The hull seems to be one giant piece of coral, coated with a "
    "shell of barnacles and mollusks. Sails sewn of seaweed stretch between "
    "masts of driftwood, and giant clamshell catapults line the deck."
  );
  SetBridgeDescription(
    "It's hard to keep a steady footing here, as flotsam and silt cover the deck "
    "nearly a handspan deep. The smell is less than pleasant, though perhaps somewhat "
    "nostalgic to the average Parvan. Crabs and various other sea critters dart and "
    "slither about."
  );
  SetCaptain("sea nymph");
  SetCrystals(40000);
  SetDamagePoints(800000);
  SetDriveSystem(VM_DEEP);
  SetPrizeBonus(16);
  SetShieldSystem(VSH_SMALL);
  SetSensorSuite(VSE_WIDE);
  SetVehicleSize(VS_CRUISER);
  SetWeaponSystem(VW_MEDIUM);
}

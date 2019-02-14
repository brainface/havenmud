#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("warship");
  SetShort("a goden skeid");
  SetId( ({ "ship", "craft", "skeid" }) );
  SetAdjectives( ({ "goden" }) );
  SetLong("This is a goden skeid, an immense longship gliding through in the "
    "water, its hull lined with shields and skulls of fallen foes. A single "
    "mast holds aloft a blood red sail, while a score of oars cut into the "
    "water on each side.");
  SetBridgeDescription("The thin deck of this ship holds little room for "
    "maneuvering, with ropes, supplies, and water barrels crammed between the "
    "mast and rower's benches. A half-dozen ballista are arranged to provide "
    "fire in every direction, barrels of pitch nearby for added flame.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_CRUISER);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(400);
  SetWeaponSystem(VW_MEDIUM);
  SetShieldSystem(VSH_SMALL);
  SetPrizeBonus(8);
  SetCaptain("pirate captain");
}


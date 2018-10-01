#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_RACE_SPECIAL;

static void create() {
  ::create();
  SetRaceName("smurf");
  SetLightSensitivity( ({ 10, 65 }) );
  SetLanguage("Smurf");
  SetStartingAge(0);
  SetStat("intelligence", 20, 1);
  SetStat("strength", 20, 3);
  SetResistance(MAGIC, "low");
  SetLimb("torso", 0, 1, A_SHIRT|A_VEST|A_ARMOUR|A_AMULET);
  SetLimb("head", "torso", 1, A_HELMET|A_VISOR);
  SetLimb("arm", "torso", 2, A_GLOVE|A_WEAPON|A_RING);
  SetFingers(4);
}

/* A holy scion */
//  mahkefel mar '10
//    added armour
//    changed size to medium
//    (to make loot useful to
//     medium people)
// mahk 2018: added angel race, speech
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("scion");
  SetShort("a Holy Scion");
  SetId( ({ "scion" }) );
  SetAdjectives( ({ "holy" }) );
  SetLong(
    "A Holy Scion is a creature of pure good that wanders the Upper "
    "Planes for eternity."
  );
  SetGender("male");
  SetRace("angel");
  SetClass("priest");
  SetLevel(100);
  SetCombatAction( 40, ({
    "!cast superior wrath",
    "!cast perfect recovery on me",
  }) );
  SetFirstCommands( ({
    "cast wall of force",
    "cast wall of force",
  }) );
SetAction(5, ({
  	  "!emote hovers gracefully in the air, white wings barely flapping.",
      "!say Dost thou come in peace and walk in the law?"
}) );
  SetInventory( ([
     PLANE_OBJ + "halo" : "wear halo",
     PLANE_OBJ + "sapphire" : random(5),
     PLANE_OBJ + "mithril_bow" : "wield bow",
     PLANE_OBJ + "golden_vest" : "wear vest",
     PLANE_OBJ + "golden_cuisse" : "wear cuisse",
  ]) );
  SetMorality(2000);
  SetReligion("Kylin");
  SetSize(SIZE_MEDIUM); // cheat'n
  SetSkill("projectile combat",204,1); // use a bow good.
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
      eventForce("cast wall of force");
 }
}

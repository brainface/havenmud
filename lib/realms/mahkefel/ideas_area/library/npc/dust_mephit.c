/* A minor opponent for Arcanith
 * mahkafel october '10
 */

#include <lib.h>
#include <damage_types.h>
//#include "../arc_library.h"
inherit LIB_NPC;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("dust mephit");
  SetId( ({ "mephit"}) );
  SetAdjectives( ({ "dust" }) );
  SetShort("a dust mephit");
  SetLong(
    "This imp-like creature is covered in dust and grime from the "
    "ruined library. Two red, glowing eyes rest in a face set in a "
    "perpetual frown. Originally conjured as an assistant to the many "
    "mages of Arcanith, this sad creature seems to have lost all purpose "
    "after outliving its summoners."
  );
  SetGender("male");
  SetRace("demon","mephit");
  SetBaseLanguage("Archaic");
  SetClass("mystic");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  SetLevel(15);
  SetAction(5, ({
    "!emote mopes.",
    "!emote flaps his wings listlessly.",
    "!emote just can't seem to go on.",
    "!speak Look at what was lost!",
    "!speak Have you seen my friend?",
    "!speak Where has everyone gone?",
  }) );
  SetMorality(100);
  SetCombatAction(20, ({
    "!cast terra",
    "!emote sob",
  }) );
  SetDie("The dust mephit collapses to the floor with a final pitiful sob.");
  SetMeleeAttackString("%^orange%^grimy%^reset%^ paw");
  SetMeleeDamageType(SLASH);
  SetResistance(ALL_DAMAGE, "low"); // reset resistances
  SetResistance(ALL_PHYSICAL, "medium");
  SetResistance(WATER, "weakness");
}

void init() {
  npc::init();
}


//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("thoth");
  SetId( ({ "thoth", "master", "knowledge" }) );
  SetRace("gnoll");
  SetLevel(50);
  SetShort("Thoth, Knowledge Master");
  SetLong(
    "Thoth is a more aged gnoll who imparts his knowledge "
    "on the students here at the Great Library. His beady dark "
    "eyes take everything in almost in a bird-like manner.");
  SetGender("male");
  SetClass("evoker");
  SetTown("Lisht");
  SetBaseLanguage("Rehshai");
  SetMorality(-100);
  SetSpellBook( ([
    "chain lightning" : 100,
    "enhanced buffer" : 100,
    "enhanced aura"  : 100,
  ]) );
  SetAction(5, ({
    "!speak I will train you, if that is what you seek.",
    "!cast enhanced buffer",
    "!cast enhanced aura",
    "!emote cuffs a fractious student.",
  }) );
  SetCombatAction(50, ({
    "!cast enhanced aura",
    "!cast enhanced buffer",
    "!cast chain lightning",
  }) );
  SetInventory( ([
    LISHT_OBJ "shenti" : "wear shenti",
  ]) );
SetTrainingSkills( ({
"pole combat",
"textile working",
"leather working",
}) );
}

// Mahkefel jan 2011
// repair skill trainer for arcanith

#include <lib.h>
#include "../ruins.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Carzli");
  SetId( ({ "carzli","smith","kobold" }) );
  SetAdjectives( ({ "artzil", "miner", "a", "kobold" }) );
  SetShort("Carzli, a kobold smith");
  SetLong(
    "This exceptionally singed woman is the resident smith of "
    "arcanith. Though lacking the tools and expertise to make armaments, "
    "she has produced a constant stream of nails, brackets, sprockets and "
    "other tools needed for new construction and repair in the ruins."
  );
  SetRace("kobold");
  SetClass("merchant");
  SetGender("female");
  SetLevel(10);
  SetMorality(25);
  SetAction(10, ({
    "!stamps out a fire on the ground.",
    "!yelps as her fur catches fire.",
    "!grabs a pot from the forge with her gloved hands.",
    "!say You want smith? This one teach how?",
    "!say Help make nails?",
  }) );
  SetDie("Carzli coughs up a thick cloud of black smoke and "
    "crumples to the ground.");
  SetTown("Arcanith");
  SetTrainingSkills( ({
    "mithral working",
    "metal working",
    "natural working",
    "leather working",
    "wood working",
    "armour smithing",
    "weapon smithing",
    "cooking",
  }) );
  SetInventory( ([
    OBJ "/smith_glove" : 2,
    OBJ "/smith_goggles" : "wear goggles",
  ]) );
  SetFirstCommands( ({
    "wear first glove on right hand",
    "wear first glove on left hand",
  }) );
}


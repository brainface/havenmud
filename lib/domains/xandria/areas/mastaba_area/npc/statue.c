//Selket@Haven
//2006
#include <lib.h>
#include "../mastaba.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("statue");
  SetMorality(-350);
  SetId( ({ "statue", "woman", "bird" }) );
  SetAdjectives( ({ "bird", "protective" }) );
  SetShort("a protective statue");
  SetLong("This statue is a living creature, sworn to protect the corpse "
          "underneath this chamber, since it cannot protect itself. The "
          "statue glitters golden, a graceful woman with outstretched "
          "birdlike wings. Her eyes are filled with the flames of a "
          "baleful anger of a thousand suns. ");
  SetRace("elemental");
  SetBaseLanguage("Rehshai"); // Mahkefel 2011: players can't know elemental
  SetClass("evoker");
  SetLevel(60);
  SetGender("female");
  SetEncounter(100);
  SetSpellBook( ([
    "chain lightning" : 100,
    "disintegrate" : 100,
    "energy field" : 100,
      "paralysis" : 100,
    ]) );
  SetCombatAction(50, ({ 
     "!cast paralysis"
    "!cast chain lightning",
     "!cast disintegrate",
     }) );
  SetFirstCommands( ({
    "!cast energy field",
    "!cast energy field",
    "!cast energy field",
    "!cast energy field",
    "!cast energy field",
    }) );
  SetDie("The statue disappears with a wail of defeat.");
  SetNoCorpse(1);
}

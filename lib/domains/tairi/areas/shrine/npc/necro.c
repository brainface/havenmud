#include <lib.h>
#include "../shrine.h"

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("taketori");
  SetId( ({ "taketori", "washizu", "necromancer" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Tai");
  SetClass("necromancer");
  SetShort("Washizu Taketori the Advocate of the Profane");
  SetLong("Years of being around the dead have taken their"
          " toll on Taketori's appearance. His hollow face"
          " bears no resemblance to a living being, and"
          " his empty eyes express an amoral mindset"
          " and a general sense of disparagement to"
          " anything sacred. While thin and frail"
          " looking, Washizu Taketori is undoubtedly"
          " a skilled magician and should not be"
          " trifled with.");
  SetMorality(-1500);
  SetLevel(30);
  SetSpellBook( ([
    "necromantic shield" : 100,
    "acid blast" : 100,
    "curse" : 100,
    "cloud kill" : 100,
    "wound" : 100,
        ]) );
  SetCurrency("koken", 3000);
  SetAction(5, ({
    "!cast necromantic shield",
    "!emote rubs his hands together.",
    "!muah",
    "!grin",
    "!speak The army is nearly ready....Muah.. Muahah...Muahahahaha!",
    }) );
  SetCombatAction(50, ({
    "!cast cloud kill",
    "!cast wound",
    "!cast acid blast",
    "!cast curse",
    "!cast necromantic shield",
    "!speak When I kill you, I'll add you to my army",
    }) );
  SetInventory( ([
     SHRINE_OBJ "necro_robe" : "wear robe",
     SHRINE_OBJ "necro_knife" : "wield kris",
     SHRINE_OBJ "necro_hat" : "wear hat",
    ]) );
  SetFirstCommands( ({ 
    "cast necromantic shield", 
    "cast necromantic shield", 
    }) );
}




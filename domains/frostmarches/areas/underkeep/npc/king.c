//
// King Radchek, evil boss man
// created by Ranquest@Haven
//
#include <lib.h>
#include <damage_types.h>
#include "main.h"
 inherit LIB_NPC;

static void create() {
  npc::create();
  SetShort("King Radchek");
  SetLong("King Radchek himself is here, a hollow, wizened husk "
    "of the warlord that he once was. Nevertheless, his yellowed, aged "
    "eyes show the spark of intelligence that indicates he is still "
    "aware of his surroundings, and also the spark of madness "
    "of a man imprisoned in his own tomb for all these millenia.");
  SetKeyName("king");
  SetId(( {"radchek", "king"}));
  SetAdjectives ("king");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("wraith");
  SetNoCorpse(1);
  SetDie("The King gives a final scream, and shrivels into nonexistence.");
  SetClass("fighter");
  SetLevel(50);
  SetCurrency("crystals", 400);
  SetGender("male");
  SetEncounter(60);
  SetInventory( ([
      RNQ_OBJ + "jewelled_axe" : "wield axe",
      ]) );
  SetMeleeDamageType(COLD);
  SetAction(5, ({
      "!emote stirs fitfully.",
      "!emote shifts his feet.",
      "!sneeze"
      }) );
  SetCombatAction(9, ({
      "!say What are you doing here?",
      "!disorient",
      "!disarm",
      "!say No-one's going to steal my crown!",
      "!emote growls in rage.", 
      "!emote snarls.",
      "!say I'll kill you like the rest!"
       }) );
}

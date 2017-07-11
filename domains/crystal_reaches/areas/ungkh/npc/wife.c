//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Wife");
  SetId( ({ "giant", "giantess", "wife" }) );
  SetShort("Wife, the Giantess");
  SetLong("This is a hulking giantess, and although the size of a "
          "sturdy pine tree, she is nonetheless quite pretty as "
          "giants go. She answers to the name Wife, since she is "
          "quite unintelligent and cannot remember being called "
          "anything else before her marriage to Big Snow.");
  SetRace("giant");
  SetClass("fighter");
  SetTown("Ungkh");
  SetLevel(140);
  SetGender("female");
  SetMorality(-50);
  SetLimit(1);
  SetBaseLanguage("Uruk");
  SetAction(1, ({
    "!say Who you? You not Snow. Only Snow allowed here.",
    "!emote sucks her teeth thoughtfully.",
    "!grunt softly",
    "!scratch suggestively",
    "!say I yell for Snow if you not get out of here.",
    "!emote eyes you suspiciously.",
    }) );
  SetCombatAction(1, ({
    "!grunt hysterically",
    "!roar",
    }) );
  SetCurrency("skins", 500+random(150));
  SetInventory(([
    U_OBJ "rollingpin" : "wield rolling pin",
  ]) );
}

int eventDie(object killer) {
  object orc_inv;
  object orc_inv_2;
  if(!random(500)) {
     orc_inv = new(DIR_INVASIONS + "/jidoor_orc/oij_inv");
    INVASION_D->eventRegisterInvasion(orc_inv, killer);
     orc_inv_2 = new(DIR_INVASIONS + "/jidoor_orc/oij_2_inv");
    INVASION_D->eventRegisterInvasion(orc_inv_2, killer);
  }
  return ::eventDie(killer);
}

//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Stonecrusher");
  SetId( ({ "giant", "stonecrusher" }) );
  SetAdjectives( ({ "snarly" }) );
  SetShort("Stonecrusher");
  SetLong("Stonecrusher is a mountain of smelly muscles and teeth, "
          "but somehow considered to be the most handsome of his "
          "brothers. He leads their exploits and seems to be moderately "
          "intelligent, when he's not busy stabbing anyone just to "
          "make their insides into their outsides.");
  SetRace("giant");
  SetClass("fighter");
  SetTown("Ungkh");
  SetLevel(140);
  SetGender("male");
  SetMorality(-350);
  SetBaseLanguage("Uruk");
  SetLimit(1);
  SetAction(1, ({
    "!say Look at puny man-thing. I wonder if it good for eat.",
    "!emote prods you with one thick finger to see if you are tender.",
    "!grunt thoughtfully",
    "!say Stupid man-things keep coming here. We eat you!",
    "!flex",
    "!mutter",
    }) );
  SetCombatAction(1, ({
    "!roar",
    "!disorient",
    }) );
  SetCurrency("skins", 500+random(150));
  SetInventory(([
    U_OBJ "bigsword" : "wield sword",
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

//Selket@Haven
//2006
#include <daemons.h>
#include <lib.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Stump");
  SetId( ({ "giant", "stump" }) );
  SetAdjectives( ({ "snarly" }) );
  SetShort("Snarly Stump");
  SetLong("Stump is a giant with a huge scar that has disfigured "
          "his not innately handsome face and made it so he bears "
          "a permenant snarl, showing yellowed crowded teeth. He "
          "seems quite capable of making a stump out of any body "
          "bearing limbs with his enormous axe.");
  SetRace("giant");
  SetClass("fighter");
  SetTown("Ungkh");
  SetLevel(140);
  SetGender("male");
  SetMorality(-200);
  SetBaseLanguage("Uruk");
  SetLimit(1);
  SetAction(1, ({
    "!say I kill you good, fleshbag.",
    "!emote drool",
    "!grunt loudly",
    "!say Stop look my face, stupid fleshbag.",
    "!emote snarls.",
    "!emote snarls.",
    }) );
  SetCombatAction(1, ({
    "!emote snarls.",
    "!roar",
    }) );
  SetCurrency("skins", 500+random(150));
  SetInventory(([
    U_OBJ "axe" : "wield axe",
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

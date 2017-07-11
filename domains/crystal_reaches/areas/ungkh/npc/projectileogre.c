//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("yellow ogre");
  SetId( ({"ogre"}) );
  SetShort("a yellow ogre");
  SetAdjectives( ({"yellow"}) );
  SetLong(
    "This slouching ogre is completely covered in dull yellowish scales. "
    "A pair of huge curling horns surmounts his hideous head, which "
    "turns from side to side as he moves, sniffing out enemies. He "
    "seems very capable of using his powerful crossbow.");
  SetRace("ogre");
  SetGender("male");
  SetClass("ranger");
  SetTown("Ungkh");
  SetLevel(120);
  SetCurrency("skins",300 + random(200) );
  SetMorality(-200);
  SetAction(5, ({
    "!grunt",
    "!emote stares blankly ahead.",
    "!spit",
    "!emote scratches himself.",
    "!emote eats a flea.",
    }) );
  SetFriends( ({ "yellow ogre" }) );
  SetCombatAction(3, ({
    "!say huh?",
    "!emote growls deeply and menacingly.",
    "!emote leers at you.",
    "!frown",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic",
    U_OBJ "crossbow" : "wield crossbow", 
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

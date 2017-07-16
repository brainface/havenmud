//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("red ogre");
  SetId( ({"ogre"}) );
  SetShort("a red ogre");
  SetAdjectives( ({"red"}) );
  SetLong(
    "This slouching ogre is completely covered in dull red scales. "
    "A pair of huge curling horns surmounts his hideous head, which "
    "turns from side to side as he moves, sniffing out enemies. He "
    "seems very capable of using his enormous staff.");
  SetRace("ogre");
  SetGender("male");
  SetClass("fighter");
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
  SetFriends( ({ "red ogre" }) );
  SetCombatAction(3, ({
    "!say huh?",
    "!emote growls deeply and menacingly.",
    "!emote leers at you.",
    "!frown",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic",
    U_OBJ "staff" : "wield staff", 
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

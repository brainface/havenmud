//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <daemons.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("brown ogre");
  SetId( ({"ogre"}) );
  SetShort("a brown ogre");
  SetAdjectives( ({"brown"}) );
  SetLong(
    "This slouching ogre is completely covered in filthy brown scales. "
    "A pair of huge curling horns surmounts his hideous head, which "
    "turns from side to side as he moves, sniffing out enemies. He "
    "seems very capable of using his club.");
  SetRace("ogre");
  SetGender("male");
  SetTown("Ungkh");
  SetClass("fighter");
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
  SetFriends( ({"brown ogre"}) );
  SetCombatAction(3, ({
    "!say huh?",
    "!emote growls deeply and menacingly.",
    "!emote leers at you.",
    "!frown",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic",
    U_OBJ "club" : "wield club", 
    ]) );
  }

int eventDie(object killer) {
  object ogre_inv;
  if(!random(500)) {
     ogre_inv = new(DIR_INVASIONS + "/soleil_ogre/ois_inv");
    INVASION_D->eventRegisterInvasion(ogre_inv, killer);
  }
  return ::eventDie(killer);
}

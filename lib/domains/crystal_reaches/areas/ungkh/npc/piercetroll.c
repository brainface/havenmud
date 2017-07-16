//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <daemons.h>
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("cruel troll");
  SetId( ({ "troll", "troll_wander" }) );
  SetShort("a cruel troll");
  SetAdjectives( ({"cruel"}) );
  SetLong(
    "This troll is known for his undenyable cruelty towards others. He, "
    "like others of his kind, has a pair of small, pointed horns and a "
    "set of dirty claws that protrude from his yellowish-brown hide."
    "As he strolls around the town, he kicks dirt clods out of the street "
    "just out of spite.");
  SetRace("troll");
  SetGender("male");
  SetClass("cavalier");
  SetTown("Ungkh");
  SetMorality(-200);
  SetLevel(100);
  SetWander(2);
  SetEncounter( (:eventCheckPlayer:) );
  SetCurrency("skins", 300 + random(200) );
  SetAction(5, ({
    "!roar",
    "!emote stamps on some grass to kill it.",
    "!spit",
    "!emote shoves you roughly.",
    }) );
  SetFriends( ({"angry troll", "suspicious troll", "fierce troll",
    "cruel troll" }) );
  SetCombatAction(3, ({
    "!emote kicks dirt into your face.",
    "!growl",
    "!roar",
    "!shout Get out!",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic", 
    U_OBJ "lance" : "wield lance",
    ]) );
  }
int eventCheckPlayer() {
    object who = this_player();
    if (userp(who)) {
    SetAttack(who);
    return 1;
  }
  else return 0;
 }

int eventDie(object killer) {
  object ogre_inv;
  if(!random(500)) {
     ogre_inv = new(DIR_INVASIONS + "/soleil_ogre/ois_inv");
    INVASION_D->eventRegisterInvasion(ogre_inv, killer);
  }
  return ::eventDie(killer);
}

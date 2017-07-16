//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("fierce troll");
  SetId( ({"troll", "troll_wander"}) );
  SetShort("a fierce troll");
  SetAdjectives( ({"fierce"}) );
  SetLong(
    "This is an extremely fierce troll, with short pointed horns and "
    "dirt-encrusted claws protruding from his dark brown, thick-skinned "
    "massive body. Grimacing to show off his sharp, dirty teeth, he "
    "threatens everyone he comes in contact with just to see if they "
    "will take him up on the challenge.");
  SetRace("troll");
  SetGender("male");
  SetTown("Ungkh");
  SetClass("rogue");
  SetMorality(-200);
  SetLevel(100);
  SetWander(2);
  SetEncounter( (:eventCheckPlayer:) );
  SetCurrency("skins", 300 + random(200) );
  SetAction(5, ({
    "!roar",
    "!say Wanna fight, stupid?",
    "!emote cracks his enormous knuckles.",
    "!emote shoves you tauntingly.",
    }) );
  SetFriends( ({"angry troll", "suspicious troll", "fierce troll",
    "cruel troll" }) );
  SetCombatAction(3, ({
    "!taunt",
    "!growl",
    "!roar",
    "!shout Get out!",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic", 
    ]) );
  }

int eventCheckPlayer() {
    object who = this_player();
    if (userp(who)){
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

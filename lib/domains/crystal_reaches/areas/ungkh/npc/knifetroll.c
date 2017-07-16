//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

int eventCheckPlayer();
static void create() {
  npc::create();
  SetKeyName("suspicious troll");
  SetId( ({"troll", "troll_wander"}) );
  SetShort("a suspicious troll");
  SetAdjectives( ({"suspicious"}) );
  SetLong(
    "This is a very suspicious troll, with short pointed horns and "
    "dirt-encrusted claws protruding from his dark green, thick-skinned "
    "massive body. He casts his piggish eyes around suspiciously on "
    "everything that comes near him, ready to stab it thoroughly, should "
    "it prove dangerous to him or his friends.");
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
    "!say I knew you were trouble!",
    "!emote readies his knife for surprise combat.",
    "!emote shoves you.",
    }) );
  SetFriends( ({"angry troll", "suspicious troll", "fierce troll",
    "cruel troll" }) );
  SetCombatAction(3, ({
    "!emote stabs at you almost accusingly.",
    "!growl",
    "!roar",
    "!shout Get out!",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic",
    U_OBJ "knife" : "wield knife", 
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

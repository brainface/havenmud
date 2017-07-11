//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("angry troll");
  SetId( ({ "troll", "troll_wander" }) );
  SetShort("an angry troll");
  SetAdjectives( ({"angry"}) );
  SetLong(
    "This is a habitually angry troll, with short pointed horns and "
    "dirt-encrusted claws protruding from his green, thick-skinned "
    "massive body. As he wanders about, he swings his axe at anyone "
    "who gets in his way.");
  SetRace("troll");
  SetGender("male");
  SetClass("fighter");
  SetTown("Ungkh");
  SetLevel(100);
  SetMorality(-200);
  SetWander(2);
  SetEncounter( (: eventCheckPlayer :) );
  SetCurrency("skins", 300 + random(200) );
  SetAction(5, ({
    "!roar",
    "!say Get out of here!",
    "!emote pushes someone out of the way with the sharp side of his axe.",
    "!emote shoves you.",
    }) );
  SetFriends( ({"angry troll", "suspicious troll", "fierce troll",
    "cruel troll" }) );
  SetCombatAction(3, ({
    "!emote shoves you fiercely.",
    "!growl",
    "!roar",
    "!shout Get out of here!",
    }) );
  SetInventory( ([
    U_OBJ "tunic" : "wear tunic",
    U_OBJ "axe" : "wield axe", 
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

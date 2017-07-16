// Leader of the Bandit vs Parva Invasion
// Original Coder: Unknown
// Edited by: Laoise, 2005

#include <lib.h>
#include "../bip.h"
inherit LIB_INVADER;

int CheckParva();

static void create() {
  ::create();
  SetKeyName("bandit captain");
  SetEnemyTown("Parva");    
  SetShort("a skaven bandit captain");
  SetId( ({ "captain", "bandit captain", "skaven", "bandit_inv" }) );
  SetAdjectives( ({ "bandit", "skaven" }) );
  SetLong(
    "This skaven is the leader of this rag-tag bunch "
    "of scum."
  );
  SetRace("skaven");
  SetGender("male");
  SetClass("fighter");
  SetLevel(15);
  SetMorality(-300);
  SetInventory( ([
    BIP_OBJ + "sword" : "wield sword",
    BIP_OBJ + "leather" : "wear leather",
  ]) );
  SetCurrency("imperials", 250);
  SetAction(5, ({
    "!yell Rape the town!",
    "!yell Search out the money!",
    "!yell Loot the town!",
  }) );
  SetCombatAction(15, ({
     "!yell My men, to me!",
     "!slice",
     "!say You'll pay for this, filth.",
  }) );
  SetFriends( ({ "bandit_inv" }) );
  SetEncounter( (: CheckParva :) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "enter hall", "go out", "go east", "enter shack", "go out",
    "go south",
    "go north", "go east", "enter store",
    "go out", "enter inn", "go out", "go east", "go north",
    "go south", "go south",
  }) );
}

int CheckParva() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader"))) {
    eventForce("say You'll die for this!");
    SetAttack(who);
  return 1;
  }
return 0;
}

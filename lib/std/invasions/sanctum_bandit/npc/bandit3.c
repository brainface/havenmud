// Bandit invasion of Sanctum
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../bis.h"

inherit LIB_INVADER;

int CheckInvader(object);

static void create() {
  invader::create();
  SetKeyName("bandit");
  SetShort("a ragged-looking bandit");
  SetId( ({ "bandit" }) );
  SetAdjectives( ({ "ragged","looking" }) );
  SetLong(
    "This human is obviously nothing more than a simple bandit "
    "out for a little pillaging."
  );
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(10)+5);
  SetInventory( ([
    BIS_OBJ + "chainmail" : "wear chainmail",
    BIS_OBJ + "sword" : "wield sword in right hand",
  ]) );
  SetCurrency("ducats", random(20));
  SetAction(5, ({
    "!yell Quick, over here!",
    "!speak You'll die now, little ones.",
    "!yell Die peasants!",
    "!yell Sack the town!",
  }) );
  SetFriends( ({ "bandit_inv" }) );
  SetEncounter( (: CheckInvader :) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "go south", "go south", "go south", "go south", "go south", "go south",
    "enter bazaar" 
  }) );
}

int CheckInvader(object who) {
  if (who->GetProperty("invader")) return 0;
    eventForce("attack " + who->GetKeyName());
  return 1;
}

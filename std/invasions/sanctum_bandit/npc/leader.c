// Bandit invasion of Sanctum
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../bis.h"

inherit LIB_INVADER;

void eventUseWand();
int CheckInvader(object);

static void create() {
  invader::create();
  SetKeyName("bandit leader");
  SetShort("a ragged-looking bandit leader");
  SetId( ({ "bandit", "leader", "bandit_inv" }) );
  SetAdjectives( ({ "ragged", "looking" }) );
  SetLong(
    "This human is obviously nothing more than a simple bandit "
    "out for a little pillaging."
  );
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(20)+12);
  SetInventory( ([
   BIS_OBJ + "chainmail" : "wear chainmail",
   BIS_OBJ + "sword"     : "wield sword in right hand",
   BIS_OBJ + "wand"      : "wield wand in left hand",
  ]) );
  SetCurrency("ducats", random(50));
  SetAction(5, ({
    "!yell Quick, over here!",
    "!speak You'll die now, little ones.",
    "!yell Die peasants!",
    "!yell Sack the town!",
  }) );
  SetCombatAction(5, (: eventUseWand :) );
  SetFriends( ({ "bandit_inv" }) );
  SetEncounter( (: CheckInvader :) );
  SetWanderSpeed(3);
  SetWanderPath( ({ 
    "go south", "go south", "go south", "go west", "go west", "go west",
    "go south", "enter coloseum"
  }) );
}

void eventUseWand() {
  object target = GetCurrentEnemy();
  if (!target) return;
    eventForce("use wand to paralyze " + target->GetKeyName());
  return;
  }

int CheckInvader(object who) {
  if (who->GetProperty("invader")) return 0;
    eventForce("attack " + who->GetKeyName());
  return 1;
}

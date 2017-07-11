/* Zeratul@Haven */

#include <lib.h>
#include <domains.h>
#include <config.h>
#include "../undead.h"

inherit LIB_SENTIENT;

int CheckAttack(object);

static void create() {
  sentient::create();
  SetKeyName("zombie");
  SetId( ({ "zombie","creature","guard_shrine" }) );
  SetShort("an awakened zombie creature");
  SetLong(
     "This zombie like creature looks to be as confused as it is angry. This hunk "
     "of rotting flesh and bones stumbles around, obviously agitated that it has "
     "awakened from its grave. "
  );
  SetLevel(random(10)+15);
  SetLimit(4);
  SetUndead("zombie");
  SetRace("human");
  SetMorality(-150);
  SetAction(1, ({
     "!emote groans painfully.",
     "!say arrrrruugghhgh",
     "!say uuuggghhherrmmm",
     "!say oohhrrnrnrnmmgghhrrh",
     "!say rrrrrrrgggghhhnhhh",
  }) );
  SetEncounter( (: CheckAttack :) ),
  SetInventory( ([
  ]) );
  SetFriends( ({
     "guard_shrine"
  }) );
  SetCurrency("ducats", random(100)+150);
  }

int CheckAttack(object who) {
if (this_player()->GetLevel() < MAX_NEWBIE_LEVEL) return 0;
if (this_player()->GetClass("necromancer")) return 0;
if (this_player()->id("guard_shrine")) return 0;
     eventForce("attack " + who->GetKeyName());
     return 1;
}


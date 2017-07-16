// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <damage_types.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("guard dog");
  SetId( ({ "dog", "we_wander" }) );
  SetAdjectives( ({ "mean","looking","guard" }) );
  SetShort("a mean-looking guard dog");
  SetLong(
     "This large almost wolf-like dog stands tall and strong. Sharp teeth with a "
     "powerful set of jaws give this animal power over unsuspecting enemies. The "
     "fur on this animal looks patchy in some areas, suggesting this dog has seen "
     "many fights with animals and men. "
  );
  SetLimit(1);
  SetWander(1);
  SetWanderSpeed(2);
  SetWanderPath( ({
     "go west", "go west", "go east", "go east",
  }) );
  SetWanderRecurse(1000);
  SetGender(random(2) ? "male" : "female");
  SetRace("dog");
  SetClass("animal");
  SetLevel(random(5) + 10);
  SetMeleeAttackString("bite");
  SetMeleeDamageType(PIERCE);
  SetFriends( ({
     "we_wander",
  }) );
  SetProperty("no bump", 1);
  SetAction(1, ({
     "!emote barks. ",
  }) );
  SetCombatAction(1, ({
  }) );
}


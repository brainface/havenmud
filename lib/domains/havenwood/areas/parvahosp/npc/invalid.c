
#include <lib.h>
#include "../ph.h"
#include <damage_types.h>
inherit LIB_NPC;

int timer = 5;

static void create() {
  ::create();
  SetKeyName("invalid");
  SetShort("an invalid");
  SetId( ({ "invalid" }) );
  SetAdjectives( ({}) );
  SetLong(
    "Slowly recuperating from wounds that were inflicted "
    "long ago, the invalid waits for full recovery."
  );
  SetRace( ({ "muezzin","human","human","gelfling","halfling" })[random(5)]);
  SetClass("rogue");
  SetLevel(2);
  SetGender( ({ "male","female" })[random(2)]);
  SetAction(1, ({ 
    "!emote supresses a moan.",
    "!emote tests out " + possessive(this_object()) + " limbs." 
  }) );
  SetCurrency("oros",9);
  set_heart_beat(2);
  AddHealthPoints(-(GetHealthPoints()/3));
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer){
      timer = 4;
    eventReceiveDamage(0, BLUNT, GetHealthPoints()/5, 0, GetRandomLimb("torso"));
      eventForce("!emote winces quietly.");
   }
}

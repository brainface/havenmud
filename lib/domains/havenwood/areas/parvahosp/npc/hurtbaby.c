#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

int timer = 10;

static void create() {
  ::create();
  SetKeyName("infant");
  SetShort("a small infant");
  SetId( ({ "infant","baby" }) );
  SetAdjectives( ({ "small" }) );
  SetLong(
    "Weak and helpless, the little baby appears to have little clue of "
    "what is occuring in the surrounding world."
  );
  SetRace("human");
  SetClass("animal");
  SetLevel(2);
  SetGender( ({ "male","female" })[random(2)]);
  
  SetAction(1, ({ 
    "!emote waves " + possessive(this_object()) + " tiny fists around "
    "in the air.",
    "!emote opens " + possessive(this_object()) + " mouth "
    "wide and emits a small cry." 
  }) );
  SetMorality(2000);
  set_heart_beat(2);
  AddHealthPoints(-(GetHealthPoints()/4));
}

void heart_beat() {
  ::heart_beat();
  timer--;
  if(!timer) {
    eventReceiveDamage(0, BLUNT, (GetHealthPoints()/7), 1);
    timer = 5;
    if(random(2)) { eventForce("!emote cries."); }
  }
}

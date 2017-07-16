#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

int timer = 10;

static void create() {
  ::create();
  SetKeyName("infant");
  SetShort("a recovering infant");
  SetId( ({ "infant","baby" }) );
  SetAdjectives( ({ "recovering" }) );
  SetLong(
    "Gaining strength daily, this lucky infant is fighting to survive while "
    "still helpless and dependant on others."
  );
  SetGender( ({ "male","female" })[random(2)]);
  SetRace("human");
  SetAction(1, ({ 
    "!emote waves " + possessive(this_object()) + " tiny fists around "
    "in the air.",
    "!emote opens " + possessive(this_object()) + " mouth "
    "wide and emits a small cry.",
    "!emote peers around at the other children." 
  }) );
  SetMorality(2000);
  set_heart_beat(2);
  AddHealthPoints(-(GetHealthPoints()/9));
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

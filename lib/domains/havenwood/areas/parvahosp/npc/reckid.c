#include <lib.h>
#include <damage_types.h>
#include "../ph.h"
inherit LIB_NPC;

int timer = 7;

static void create() {
  ::create();
  SetKeyName("child");
  SetShort("a recovering child");
  SetId( ({ "child" }) );
  SetAdjectives( ({ "recovering" }) );
  SetLong(
    "With only a few scratches and old bruises left to reveal "
    + possessive(this_object()) + " injuries, this child "
    "appears bright and happy and ready to tackle the world again."
  );
  
  SetRace("human");
  SetClass("rogue");
  SetLevel(1);
  SetGender( ({ "male","female" })[random(2)] );
 
  SetMorality(800);
  SetAction(1, ({ "!emote plays with the toys.","!emote examines a toy carefully." }) );
  set_heart_beat(2);
  AddHealthPoints(-(GetHealthPoints()/8));
  SetInventory( ([
    PO + "/horse" : 1,
    PO + "/block" : 1,
  ]) );
}

void heart_beat() {
  ::heart_beat();
  timer--;
  if(!timer) {
    eventReceiveDamage(0, BLUNT, (GetHealthPoints()/7), 1);
    timer = 5;
    if(random(2)) { eventForce("!emote whimpers a little."); }
  }
}

#include <lib.h>
#include <damage_types.h>
#include "../ph.h"
inherit LIB_NPC;

int timer = 7;

static void create() {
  ::create();
  SetKeyName("child");
  SetShort("a hurt child");
  SetId( ({ "child" }) );
  SetAdjectives( ({ "hurt" }) );
  SetGender( ({ "male","female" })[random(2)] );
  SetLong(
    "Weak and dejected, the hurt child waits for recovery. Previously "
    "malnurished in addition to the cuts and scrapes from whatever accident "
     "befell this child, " + possessive(this_object()) + " disposition "
     "brightens at the sight of smiling faces and kind doctors."
   );
   SetRace("human");
   SetClass("rogue");
   SetLevel(1);
   
   SetMorality(800);
   SetAction(1, ({ 
     "!emote plays with a toy.",
     "!emote examines a toy carefully." 
   }) );
   set_heart_beat(2);
   AddHealthPoints(-(GetHealthPoints()/5));
   SetInventory( ([
     PO + "/horse" : 1,
  ]) );
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

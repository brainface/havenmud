#include <lib.h>
#include <damage_types.h>
#include "../ph.h"
inherit LIB_NPC;
int timer = 3;
static void create() {
   ::create();
   SetKeyName("traveller");
   SetShort("a wounded traveller");
   SetId( ({ "traveller" }) );
   SetAdjectives( ({"wounded"}) );
   SetGender( ({ "male","female" })[random(2)]);
   SetLong(
     "Lucky to have stumbled upon this place, the traveller "
     "waits for healing from the resident clerics.  " + 
     capitalize(nominative(this_object())) + " appears "
     "to have been fairly new at adventuring."
   );
   
   SetRace( ({ 
     "muezzin", "human", "human", "gelfling", "halfling",
     "nosferatu", "elf", "dark-elf", "human" })[random(9)]);
   SetClass("rogue");
   SetLevel(3);
   
   SetAction(1, ({ 
     "!groan",
     "!emote moans.",
     "!emote winces." 
   }) );
   SetCurrency("oros",7);
   SetCurrency(({"imperials","cuicui","bloodgems","roni"})[random(4)],
               55+random(40));
   set_heart_beat(2);
   AddHealthPoints(-(GetHealthPoints()*3/4));
}

void heart_beat() {
  ::heart_beat(); 
  timer--;
  if(!timer) {
    timer = 4;
    eventReceiveDamage(0, BLUNT, (GetHealthPoints()/6), 1);
// Changed it to internal damage, limbs fallin off everywhere.
    eventForce("!emote moans loudly.");
  }
}

//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

int timer;

static void create() {
   npc::create();
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetKeyName("poisoned patient");
   SetShort("a poisoned patient");
   SetId( ({ "patient" }) );
   SetAdjectives( ({ "poisoned" }) );
   SetLong("This patient has been heavily poisoned, most likely by " 
           "a desert creature, and has come here for healing. There "
           "seems to be almost no hope for this poor gnoll, who is "
           "clammy and shaking. "
   );
   SetMorality(-100);
   SetRace("gnoll");
  SetBaseLanguage("Rehshai");
   AddPoison(55);
   timer = 20;
   SetClass("rogue");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(1);
   AddHealthPoints(-(GetHealthPoints()/2) );
   set_heart_beat(4);
   SetInventory( ([
                    LISHT_OBJ "shenti" : "wear shenti",
               ]) );
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer) {
      AddPoison(30);
      timer = 10;
      eventForce("!emote 's eyes close in pain.");
   }
}

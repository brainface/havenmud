//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include "../lisht.h"
inherit LIB_NPC;

int timer;

static void create() {
   npc::create();
   set_heart_beat(1);
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetKeyName("patient");
   SetShort("a wounded patient");
   SetId( ({ "patient" }) );
   SetAdjectives( ({ "wounded" }) );
   SetLong("This gnoll has been heavily wounded in battle, but "
           "is trying hard not to show any pain. Occasionally, "
           "a stifled groan breaks through the lips of this "
           "dying warrior.");
   SetRace("gnoll");
  SetBaseLanguage("Rehshai");
   SetMorality(-100);
   SetClass("rogue");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(5+random(3));
   timer = 25;
   AddHealthPoints(-(GetHealthPoints()/3 + GetHealthPoints()/8));
   SetInventory( ([
                    LISHT_OBJ "shenti" : "wear shenti",
               ]) );
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer) {
      eventReceiveDamage(0, BLUNT, 30, 0, GetRandomLimb("torso"));
      timer = 10;
      eventForce("!groan");
   }
}

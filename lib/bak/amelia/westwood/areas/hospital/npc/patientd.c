#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hospital.h"

int timer;

static void create() {
   npc::create();
   SetMorality(-50);
   SetProperty("noleavehospital",1);
   set_heart_beat(1);
   SetRace("nosferatu");
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetClass("valkyr");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(5+random(3));
   timer = 25;
   AddHealthPoints(-(GetHealthPoints()/3 + GetHealthPoints()/8));
   SetKeyName("patient");
   SetShort("a nosferatu patient");
   SetId( ({ "nosferatu","patient" }) );
   SetAdjectives( ({ "sick","nosferatu" }) );
   SetLong("The nosferatu has been heavily damaged, but is "
           "trying to hold on to life so that the Eclats can "
           "heal him.  His eyes are closed, and he does not look "
           "very well trained.");
   SetInventory( ([
                    H_OBJ + "blackrk" : random(2),
               ]) );
}

void heart_beat() {
   ::heart_beat();
   timer--;
   if(!timer) {
      eventReceiveDamage(0, BLUNT, 30, 0, GetRandomLimb("torso"));
      timer = 10;
      eventForce("!emote groans.");
   }
}


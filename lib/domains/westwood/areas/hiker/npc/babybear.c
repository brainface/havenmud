#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("baby bear");
   SetShort("a baby bear");
   SetId( ({ "bear","baby" }) );
   SetAdjectives( ({ "bear","baby" }) );
   SetLong("The baby bear is entangled in some branches, and it looks "
           "as if he's been cut up somehow.  Even though he is young, "
           "his claws have already begun to look fierce.");
   SetGender("male");
   SetRace("bear");
   SetClass("animal");
   SetLevel(2);
   SetMeleeAttackString("claws");
   SetMeleeDamageType(PIERCE);
   SetAction(8, ({ "!whimper","!emote cries softly.","!emote struggles "
                   "with the branches." }) );
   SetDie("The bear sniffles in relief and sadness.");
   eventCompleteHeal(-30);
}

void eventDie(object killer) {
   object daitem1,daitem2;
   daitem1 = new(H_OBJ + "branch");
   daitem2 = new(H_OBJ + "babyclaw");
   daitem1->eventMove(environment(this_object()));
   daitem2->eventMove(this_object());
   ::eventDie(killer);
}

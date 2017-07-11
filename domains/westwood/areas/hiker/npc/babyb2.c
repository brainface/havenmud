#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("baby bear");
   SetShort("a baby bear");
   SetId( ({ "bear","baby" }) );
   SetAdjectives( ({ "baby" }) );
   SetLong("The baby growls excitedly at the surrounding world, taking "
           "everything in with zest and zeal.  " +
           capitalize(nominative(this_object())) + " seems to miss "
           "someone or something, however, and is still too young to "
           "go off on " + possessive(this_object()) + " own to find it.");
   SetRace("bear");
   SetClass("animal");
   SetLevel(2+random(3));
   SetMeleeAttackString("claws");
   SetMeleeDamageType(PIERCE);
   SetAction(2, ({ "!growls playfully.","!emote runs around and wrestles "
                   "with " + possessive(this_object()) + " tail.",
                   "!emote pounces on a branch zealously.",
                   "!emote stalks a nearby flower, eyes glowing.",
                   "!emote digs up a pitifully small root, munching it "
                   "down voraciously.",
              }) );
}

void eventDie(object killer) {
   object dat, dis;
   dis = new(H_OBJ + "babyclaw");
   dat = new(H_OBJ + "babypelt");
   dat->eventMove(this_object());
   dis->eventMove(this_object());
   ::eventDie(killer);
}

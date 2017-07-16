#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("grizzly bear");
   SetShort("a grizzly bear");
   SetId( ({ "bear" }) );
   SetAdjectives( ({ "grizzly" }) );
   SetLong("The grizzly bear looks to be almost half a ton in weight, and "
           "she wears a fierce expression of sadness and distrust.  "
           "It looks as if she gave birth recently, and her sharp teeth "
           "are bared.");
   SetRace("bear");
   SetClass("animal");
   SetGender("female");
   SetLevel(23+random(4));
   SetMeleeAttackString("claws");
   SetMeleeDamageType(PIERCE);
   SetAction(5, ({ "!emote searches around curiously.",
                   "!emote wears a wistful expression which suddenly "
                      "turns angry as she growls.",
                   "!emote growls angrily.",
              }) );
}

void eventDie(object killer) {
   object dat,dis;
   dis = new(H_OBJ + "bearclaw");
   dat = new(H_OBJ + "bearpelt");
   dat->eventMove(this_object());
   dis->eventMove(this_object());
   ::eventDie(killer);
   // force baby to follow
}

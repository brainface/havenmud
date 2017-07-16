#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("golem");
   SetShort("a stocky human");
   SetId( ({ "human","man","golem","creature" }) );
   SetAdjectives( ({ "stocky","wooden","wood","human" }) );
   SetLong("Closer observation reveals that what seemed to be a stocky "
           "human creature is truly a wooden golem!  He is, however, "
           "quite cleverly formed:  the joints are hardly noticable "
           "and his features have little show of the wood they used "
           "to be made of.  It is likely, however, that although he "
           "looks human, he does not have the same frail softness:  "
           "he is made of wood, after all.");
   SetGender("male");
   SetRace("golem");
   SetClass("animal");
   SetLevel(52+random(3));
}

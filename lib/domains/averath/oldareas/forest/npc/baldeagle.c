// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("eagle");
   SetShort("an adult bald eagle");
   SetId( ({ "eagle" }) );
   SetAdjectives( ({ "adult","bald" }) );
   SetLong("Off-white feathers coat the bald eagle's head, denoting "
           "sexual maturity.  The remainder of the bird is covered "
           "in chocolate brown feathers.");
   SetGender(({ "female","male"})[random(2)]);
   SetRace("bird");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
//   SetClass("animal");
//   SetMeleeAttackString("claws");
//   SetMeleeDamageType(PIERCE);
   SetLevel(14);
   SetMorality(50);
   SetAction(1, ({ "!emote preens " + possessive(this_object()) + 
                   " feathers.","!emote snaps " + possessive(this_object())
                   + " beak at the air.","!emote stretches " + 
                   possessive(this_object()) + " wings."
             }) );
   SetCombatAction(1, ({ "!emote screeches." }) );
}

varargs int eventDie(object agent) {
   object feather;
   int i;
   for(i = 0; i < 6; i++) {
   feather = new(FOREST_OBJ + "baldeaglefeather");
   feather->eventMove(this_object());
   }
   return ::eventDie(agent);
}

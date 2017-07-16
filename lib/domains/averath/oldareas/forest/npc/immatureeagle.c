// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("eagle");
   SetShort("an immature bald eagle");
   SetId( ({ "eagle" }) );
   SetAdjectives( ({ "immature","bald" }) );
   SetLong("Mottled feathers of creamy brown and off-white decorate "
           "the immature bald eagle.  With a wingspan of easily "
           "one meter, the bird's sharp claws curl beneath his "
           "belly on the ends of powerful legs.");
   SetGender("male");
   SetRace("bird");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
//   SetClass("animal");
//   SetMeleeAttackString("claws");
//   SetMeleeDamageType(PIERCE);
   SetLevel(8);
   SetMorality(100);
   SetAction(1, ({ "!emote preens his feathers.","!emote snaps his "
                   "beak at the air.","!emote stretches his wings."
             }) );
   SetCombatAction(1, ({ "!emote screeches." }) );
}

// and eventDie() w/ feathers or claws or *something*

varargs int eventDie(object agent) {
   object feather = new(FOREST_OBJ + "baldeaglefeather");
   feather->eventMove(this_object());
   return ::eventDie(agent);
}

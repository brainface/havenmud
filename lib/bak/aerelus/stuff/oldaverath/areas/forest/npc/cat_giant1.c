#include <lib.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("cat");
   SetShort("a gigantic cat");
   SetId( ({ "cat" }) );
   SetAdjectives( ({ "gigantic" }) );
   SetLong("Razor sharp claws tip the paws of this monstrous feline "
           "while tawny colored fur covers the writhing of the giant "
	   "cat's muscles.  Glowing orange eyes dart around angrily as "
           "if searching for prey.");
   SetGender("female");
   SetRace("cat");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(10);
   SetAction(3, ({
                  "!emote paces furiously.",
                  "!emote flicks her tail testily."
   }) );
   SetCombatAction(2, ({ "!emote hisses violently." }) );
}
varargs int eventDie(object agent) {
   object claw = new(FOREST_OBJ + "giantcatclaw");
   claw->eventMove(this_object());
   return ::eventDie(agent);
}

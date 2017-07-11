// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("seagull");
   SetShort("a dumb seagull");
   SetId( ({ "seagull" }) );
   SetAdjectives( ({ "dumb" }) );
   SetLong("With a blunt beak and grimy feathers, the seagull has little "
           "grace and less intelligence.  However, meak survival instincts "
           "keep it alive.");
   SetGender("male");
   SetRace("bird");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(4);
   SetAction(1, ({ "!emote leaps into the air, circles, and resettles on the same "
                   "spot.","!emote pecks at a piece of flotsam.",
                }) );
}

varargs int eventDie(object agent) {
   object wings = new(FOREST_OBJ + "seagullwings");
   wings->eventMove(this_object());
   return ::eventDie(agent);
}

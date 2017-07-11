
// Amelia
#include <lib.h>
#include <domains.h>
#include <damage_types.h>
inherit LIB_NPC;


static void create() {
   ::create();
   SetKeyName("elk");
   SetShort("a majestic elk");
   SetId( ({ "elk" }) );
   SetAdjectives( ({ "majestic" }) );
   SetLong("The elk's fur fades from a rich brown at his head to a "
           "pale white-grey behind.  His four hooved legs have a "
           "sturdy, muscular shape, with his shoulder a towering "
           "two meters above the ground.  Majestic antlers "
           "sprout from the crown of his head in a massive tangle "
           "similar to a pile of branches.");
   SetGender("male");
   SetRace("deer","elk");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(10);
}

varargs int eventDie(object agent) {
   object antler = new(FOREST_OBJ + "elkantler");
   antler->eventMove(this_object());
   return ::eventDie(agent);
}


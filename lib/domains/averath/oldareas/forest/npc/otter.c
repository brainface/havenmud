// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("otter");
   SetShort("a playful otter");
   SetId( ({ "otter" }) );
   SetAdjectives( ({ "playful" }) );
   SetLong("The otter has a dark brown pelt, sleak and luxurious.  "
           "His eyes dance around, anxious to play.");
   SetGender("male");
   SetRace("dog","otter");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1); 
   SetLevel(4);
   SetMorality(20);
}

varargs int eventDie(object agent) {
  object pelt = new(AVERATH_AREAS "forest/obj/otterpelt");
  if (pelt)
   pelt->eventMove(this_object());
   return ::eventDie(agent);
}

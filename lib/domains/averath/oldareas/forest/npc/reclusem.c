// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("spider");
   SetShort("a giant brown recluse spider");
   SetId( ({ "spider" }) );
   SetAdjectives( ({ "giant","brown","recluse" }) );
   SetLong("With long, spindly legs extend from the central body of the "
           "brown recluse spider, extended out a quarter of a meter "
           "to either side.  Six eyes peer out of his head, shining "
           "with total blackness.");
   SetRace("arachnid");
   SetGender("male");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
//   SetClass("animal");
// Add melee specials later.
   SetLevel(9);
}

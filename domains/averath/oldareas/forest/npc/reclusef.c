// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("spider");
   SetShort("a female brown recluse spider");
   SetId( ({ "spider" }) );
   SetAdjectives( ({ "brown","recluse","female" }) );
   SetLong("Six eyes peer out of the brown recluse's head, the size of "
           "apples.  Eight legs enhances the size of the spider, "
           "stretching out a third of a meter to either side of the "
           "darkly colored creature.");
   SetRace("arachnid");
   SetGender("female");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
//   SetClass("animal");
// Add melee specials later.
   SetLevel(14);
}

// Amelia@Haven
#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("busy spider");
   SetId( ({ "spider" }) );
   SetAdjectives( ({ "busy","little","preoccupied","oblicious","meek" }) );
   SetShort("a busy spider");
   SetLong(
     "Tattered webs surround the busy little spider, and it works "
	   "furiously to mend them.  Preoccupied by this, it is oblivious to "
	   "the world, and its meek legs could be easily severed."
	   );
   SetRace("arachnid");
   SetClass("animal");
   SetLevel(1);
  
}
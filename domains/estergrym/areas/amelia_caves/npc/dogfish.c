// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
inherit LIB_TOUCH;
static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("ugly dogfish");
   SetId( ({ "dog","fish","dogfish" }) );
   SetAdjectives( ({ "dog","fish","ugly","wrinkled","old" }) );
   SetShort("an ugly dogfish");
   SetLong(
     "This dogfish still has some eyesight left, and seems to be "
	   "sluggish and slow, often bumping into rocks or other fish."
	 );
   SetRace("fish");
   SetClass("animal");
   SetLevel(1);
   
   SetTouch("The slightly wrinkled body of the dogfish is very slippery, "
	"like a rock that has been under water long enough to grow "
	"a little bit of moss.");
   SetSmell("The dogfish smells like an old fish.");
}
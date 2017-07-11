// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
inherit LIB_TOUCH;

static void create() {
   npc::create();
   SetProperty("grymxcavenoleave",1);
   SetKeyName("sightless catfish");
   SetId( ({ "catfish","fish","cat" }) );
   SetAdjectives( ({ "cat","fish","sightless","larger","blind" }) );
   SetShort("a sightless catfish");
   SetLong(
     "The eyes of this catfish have been completely grown over, and "
	   "now little bumps remain as a remanant of sight.  It seems to be "
	   "very competent at navigating these waters, however, and is larger "
	   "than most blind trout."
	 );
   SetRace("fish");
   SetClass("animal");
   SetLevel(3);
   
   SetTouch("The fish is slick and slimy.");
   SetSmell("Pungent fish smells come from the blind catfish.");
}
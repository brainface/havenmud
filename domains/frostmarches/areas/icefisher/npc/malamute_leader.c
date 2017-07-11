#include <lib.h>
#include <position.h>
#include "../ice.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lead dog");
  SetId( ({ "dog", "malamute" }) );
  SetAdjectives( ({ 
			"large", "unexpectedly", "female", "lead", "bitch",
	 		}) );
	SetShort("an unexpectedly large malamute");
  SetLong(
			"From her thick, all-white coat, to her intense, "
			"ice-blue eyes, the lead sled dog is the picture of "
			"robust good health. Her powerful frame is built for "
			"feats of strength and endurance, and her eyes hold no "
			"fear. Quicker and stronger than her compatriots, "
			"she looks ready to rend any challenger to shreds. "
			);
  SetRace("dog");
  SetClass("animal");
  SetPosition (POSITION_LYING);
  SetLevel(random(2) + 11);
  SetGender("female");
 }

/** Approved by Laoise at Fri Jul  9 20:22:08 2004. **/
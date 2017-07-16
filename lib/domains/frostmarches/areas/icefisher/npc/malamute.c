#include <lib.h>
#include <position.h>
#include "../ice.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("sled dog");
  SetId( ({ "dog", "malamute" }) );
  SetAdjectives( ({ 
			"powerful", "powerfully built", "male", "sled", 
			}) );  
	SetShort("a powerfully built malamute");
	SetLong(
			"From his thick grey and white coat, to his intense, "
			"ice-blue eyes, this large sled dog is the picture of "
			"robust good health. His powerful frame is built for "
			"feats of strength and endurance, and his eyes hold no "
			"fear. He looks ready to defend this camp from all "
			"intruders."
			);
  SetRace("dog");
  SetClass("animal");
  SetLevel(random(2) + 8);
  SetPosition (POSITION_LYING);

  SetGender("male");
 }

/** Approved by Laoise at Fri Jul  9 20:22:00 2004. **/
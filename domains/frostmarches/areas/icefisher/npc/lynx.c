#include <lib.h>
#include <position.h>
#include "../ice.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lynx");
  SetId( ({ "cat", "bobcat", "lynx" }) );
  SetAdjectives( ({ "enormous", "massive", "fierce"  }) );
  SetShort("a fierce lynx");
  SetLong(
			"Although she was well-hidden amidst the furs on her master's "
			"bedroll, baleful yellow eyes give away this bad-tempered, "
			"stocky wildcat's position. Her lips peel back from needle- "
			"sharp white fangs in a fierce snarl, and her claws puncture "
			"the pile of furs as she flexes them in preparation for a fight. "
			);
  SetRace("cat");
  SetClass("animal");
  SetLevel(random(2) + 9);
  SetPosition (POSITION_LYING);

  SetGender("female");
 }

/** Approved by Laoise at Fri Jul  9 20:21:55 2004. **/
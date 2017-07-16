///    Created by Severen    ///
///       Late December      ///
///          cat.c           ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create(){
    npc::create();

    SetShort("an undead cat");
    SetLong("This once cute and fuzzy kitty cat sneaks through the "
      "shadows avoiding all traces of light.  Twin pinpricks of eldritch "
      "light flash from its blank eyesockets as it regards it's surroundings "
      "with a baleful stare.  Ancient, mottled grey fur drapes from it's "
      "brittle bones.");
    SetAdjectives("cute","fuzzy","mottled");
    SetRace("cat");
    SetGender("female");
    SetClass("animal");
    SetLevel(2);
    SetKeyName("cat");
    SetId(({"undead", "cat"}));
    SetUndead(1);
    SetUndeadType("zombie");
    SetAction(10,({
			"!climb staircase",
			"!climb down staircase",
      }));
}


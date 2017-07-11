///    Created by Severen    ///
///      Early December      ///
///          rat.c           ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create(){
    npc::create();
		SetKeyName("rat");
    SetId(({"undead", "rat"}));
    SetAdjectives("undead","long","tailed");
    SetShort("an undead rat");
    SetLong("This is an undead rat. It has a long tail "
      "and pointly little ears. It's eyes glow a fierce red "
      "and it sways back and forth as it moves. There is a "
      "green froth coming from its mouth and nostrils.");
    
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
    SetLevel(1);
    SetUndead(1);
    SetUndeadType("zombie");
    SetAction(10,({
			"!climb staircase",
			"!climb down staircase",
      }));
}

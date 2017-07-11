///    Created by Severen    ///
///      Early December      ///
///         beetle.c         ///

#include <lib.h>
#include "../defs.h"
inherit LIB_NPC;

static void create(){
    npc::create();

    SetShort("an undead beetle");
    SetLong("The beetle is shiny black and has a horned "
      "nose. It's eyes are a milky black color and it makes "
      "a strange clicking noise. There is a large gash on its "
      "belly probably from the being that killed it.");
    SetRace("rodent");
    SetAdjectives("shiny","black","undead","horned");
    SetGender("male");
    SetClass("animal");
    SetLevel(1);
    SetKeyName("beetle");
    SetId(({"undead", "beetle"}));
    SetUndead(1);
    SetUndeadType("zombie");
    SetAction(10,({
			"!climb staircase",
			"!climb down staircase",
			"!emote clicks.",
      }));
}

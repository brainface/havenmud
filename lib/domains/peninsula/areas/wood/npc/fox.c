/* 5/03  Libitina  / fox for newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h";
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("fox");
    SetShort("a small fox");
    SetId( ({ "fox" }) );
    SetAdjectives( ({"small"}) );
    SetRace("dog", "fox");
    SetClass("animal");
    SetGender("male");
    SetLevel(2);
    SetLong("White whiskers protrude from this fox's red snout. His size is "
      			"small, indicating his young age. His tail is long, and flicks "
      			"from side to side. His coat is thick and red, with darker red "
      			"guard hairs."
    				);
    
    SetAction(2, ({
			"!emote walks in a slow circle, sniffing the ground.",
			"!emote's ears perk up at a sudden sound.",
      }) );
    SetCombatAction(2, ({
			"!emote snarls at you.",
			"!emote flicks his tail angrilly."
      }) );
}
varargs int eventDie(object killer) {
    object pelt;
    pelt = new(WOOD_OBJ "foxpelt.c");
    pelt->eventMove(this_object());
    npc::eventDie(killer);
}

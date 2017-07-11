/* 5/03 Libitina / deer for newbie area / wooded vale */


#include <lib.h>
inherit LIB_NPC;
#include "../wood.h";
static void create() {
    npc::create();
    SetKeyName("deer");
    SetShort("a brown deer");
    SetId( ({ "deer" }) );
    SetAdjectives( ({ "brown" }) );
    SetRace("deer");
    SetClass("animal");
    SetGender("female");
    SetLevel(2);
    SetLong("About four feet high, this female deer looks at you with "
      			"curious eyes, probably wondering if she should run or see if "
      			"you're going to offer her a treat. Her fur looks clean and warm."
    				);
    
    SetAction(2, ({
			"!emote bends down to search for grass.",
			"!emote stiffs the air.",
			"!emote pulls a berry off a bush with her mouth.",
      }) );
    SetCombatAction(2, ({
			"!emote rears back and kicks at you with her hoofs.",
			"!emote snaps at you with her teeth.",
			"!emote turns around to kick you with her hind legs."
      }) );
}

varargs int eventDie(object killer) {
    object pelt;
    pelt = new(WOOD_OBJ "deerpelt.c");
    pelt->eventMove(this_object());
    npc::eventDie(killer);
}

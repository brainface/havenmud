#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("warden");
SetId( ({ "goblin", "warden" }) );
SetAdjectives( ({ "goblin" }) );
SetShort("a goblin warden");
SetGender("female");
SetLong("This is a warden to goblin children.  Not being able to have "
        "children herself, she is hired to care for other's children.  She "
        "is about four feet tall and pale green in color.  She does not "
        "appear to be very threatening.");
SetRace("goblin");
SetClass("fighter");
SetCombatAction(30, ({
        "!say Leave the children alone.",
        "!emote scampers about to attack.",
}) );
SetAction(10, ({
        "!say The children are off playing.",
        "!say This pot with water is so heavy.",
        "!emote wobbles about carrying the pot of stuff.",
        "!emote smiles a hard smile.",
}) );
SetDie( "Warren falls limply to the ground.");
SetInventory( ([
        G_OBJ + "pot"   : "wield pot",
]) );
SetLevel(2);
SetMorality(-100);
}

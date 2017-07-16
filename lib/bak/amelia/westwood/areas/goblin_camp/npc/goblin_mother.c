#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("mother");
SetId( ({ "goblin", "mother" }) );
SetAdjectives( ({ "goblin" }) );
SetShort("a goblin mother");
SetGender("female");
SetLong("This is a mother to some goblin children.  She stands short for her "
        "race and is a very light shade of brown, different from others "
        "of her race.  She is wearing some old rags and is trying to cook "
        "something over a pot.");
SetRace("goblin");
SetClass("fighter");
SetCombatAction(30, ({
        "!say Leave my children alone.",
        "!emote scampers about to attack.",
}) );
SetAction(10, ({
        "!say Would you like to stay for dinner?",
        "!say This time of year is so nice.",
        "!emote holds up a ladel in a threatening manner.",
        "!emote smiles softly.",
}) );
SetDie( "Goblin mother falls limply to the ground.");
SetInventory( ([
        G_OBJ + "ladel" : "wield ladel",
]) );
SetLevel(2);
SetMorality(-200);
}

#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("child");
SetId( ({ "goblin","child" }) );
SetShort("a goblin child");
SetAdjectives( ({ "goblin" }) );
SetLong("This is a small goblin child.  He is about three and "
        "a half feet tall with a very dark green skin.  His "
        "muscles stand out and are very well developed.  He "
        "has a small patch of hair on his head and a dog-"
        "face like all goblins.");
SetRace("goblin");
SetClass("fisher");
SetGender("male");
SetCombatAction(30, ({
        "!say leave us alone.",
        "!say I will call others if you do not go.",
        "!emote stumbles about in an attempt to attack.",
}) );
SetAction(10, ({
        "!say go away.",
        "!emote casts his line into the lake.",
}) );
SetDie( "Goblin fisherman drops his fishing pole in slow motion as he "
        "falls to the ground.");
SetInventory( ([
        G_OBJ + "pole" : 1,
]) );
SetLevel(1);
SetMorality(-50);
}

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
SetClass("ranger");
SetGender("male");
SetCombatAction(30, ({
        "!say leave us alone.",
        "!say I will call others if you do not go.",
        "!emote stumbles about in an attempt to attack.",
}) );
SetAction(10, ({
        "!say go away.",
        "!emote takes a practice shot with his slingshot.",
}) );
SetDie( "Goblin boy drops his slingshot in slow motion as he falls to "
        "the ground.");
SetInventory( ([
        G_OBJ + "slingshot" : "wield slingshot",
]) );
SetLevel(1);
SetMorality(-50);
}

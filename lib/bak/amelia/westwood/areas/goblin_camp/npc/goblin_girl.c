#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("child");
SetId( ({ "goblin", "child" }) );
SetAdjectives( ({ "goblin" }) );
SetShort("a goblin child");
SetGender("female");
SetLong("This is a small goblin child.  She only stands about "
        "three feet tall and is dark green in color.  She "
        "has no hair and the dog-face of her goblin "
        "parents.");
SetRace("goblin");
SetClass("fighter");
SetCombatAction(30, ({
        "!say MOMMY!!!",
        "!emote whimpers.",
        "!emote cries out in pain.",
}) );
SetAction(10, ({
        "!say wanna play with me?",
        "!emote bounces a ball around you.",
        "!holds up her dolly.",
        "!emote smiles softly.",
}) );
SetDie( "Goblin girl falls limply to the ground.");
SetInventory( ([
        G_OBJ + "ball"  : "wield ball",
]) );
SetLevel(1);
SetMorality(-50);
}

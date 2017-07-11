#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("wanderer");
SetId( ({ "goblin", "wanderer" }) );
SetAdjectives( ({ "goblin" }) );
SetShort("a goblin wanderer");
SetGender("male");
SetLong("This goblin appears to be very lost and wandering about trying "
        "to find his way.  He is a dark shade of green and stands about "
        "four feet tall.  He is dressed in nothing more than rags and "
        "is without any hair on his body or head.");
SetRace("goblin");
SetClass("cavalier");
SetCombatAction(30, ({
        "!say Please leave me alone!",
        "!emote tries to run away.",
}) );
SetAction(10, ({
        "!say I seem to be lost.",
        "!emote looks over the sky.",
        "!emote wanders around the room looking for something.",
}) );
SetDie( "Goblin falls limply to the ground.");
SetLevel(15+random(10));
SetCurrency("cuicui", 300 + random(100));
SetMorality(-150);
}

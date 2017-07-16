#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("mercenary");
SetId( ({ "goblin","mercenary" }) );
SetShort("a goblin mercenary");
SetAdjectives( ({ "goblin" }) );
SetLong("This goblin appears to more cunning than most.  He "
        "has a grim look on his face and stands about six "
        "inches taller than a normal goblin.  He has a stance "
        "only a skilled fighter would use.  His skin is dark "
        "green and scarred.");
SetRace("goblin");
SetClass("fighter");
SetCombatAction(30, ({
        "!say be gone or I will slaughter you",
        "!say there are others coming, leave while you can",
        "!emote deftly moves about in an attack pattern",
        "!emote swings his sword in very skilled arcs",
}) );
SetAction(10, ({
        "!emote takes a few practice thrusts.",
        "!emote waits for some action.",
}) );
SetDie("Mercenary screams in agony!");
SetInventory( ([
        G_OBJ + "chain_armour" : "wear chainmail",
        G_OBJ + "long_sword" : "wield sword",
]) );
SetLevel(5);
SetGender("male");
SetCurrency("cuicui", 10 + random(10));
SetMorality(-500);
}

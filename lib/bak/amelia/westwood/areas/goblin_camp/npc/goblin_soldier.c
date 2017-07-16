#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("soldier");
SetId( ({ "goblin", "soldier" }) );
SetAdjectives( ({ "goblin" }) );
SetShort("a goblin soldier");
SetLong("This is a small goblin soldier.  He is light green "
        "in color and is a dog-faced thing.  He stands here "
        "on guard for anything that would seek to pass by "
        "him.  There is a determined look on his face.");
SetRace("goblin");
SetClass("barbarian");
SetCombatAction(30, ({
        "!say be gone or me smash you.",
        "!say me call boss if you not go.",
        "!emote stumbles about in his attack.",
        "!emote swings his sword wildly about in an attack.",
}) );
SetAction(10, ({
        "!emote takes a few practice swings.",
        "!emote puffs out his chest.",
}) );
SetDie("Soldier falls down in a melodramatic manner.");
SetInventory( ([
        G_OBJ + "leather_armour" : "wear leather_armour",
        G_OBJ + "short_sword" : "wield short_sword",
]) );
SetLevel(3);
SetGender("male");
SetCurrency("cuicui", 10 + random(10));
SetMorality(-400);
}

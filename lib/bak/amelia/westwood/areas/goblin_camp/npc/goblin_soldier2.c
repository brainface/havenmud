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
        "in color and is a dog-faced thing.  He appears to be very "
        "busy as he runs about trying to prepare for something.");
SetRace("goblin");
SetClass("barbarian");
SetCombatAction(30, ({
        "!emote stumbles about in his attack.",
        "!emote swings his sword wildly about in an attack.",
}) );
SetAction(10, ({
        "!emote runs about trying to move equipment.",
        "!emote moves about in a frenzy.",
}) );
SetDie("Soldier drops to the ground and bleeds over the grass.");
SetInventory( ([
        G_OBJ + "leather_armour" : "wear armour",
        G_OBJ + "short_sword" : "wield sword",
]) );
SetLevel(3);
SetGender("male");
SetCurrency("cuicui", 10 + random(10));
SetMorality(-350);
}

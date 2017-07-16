#include <lib.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("leader");
SetId( ({ "orc","leader" }) );
SetShort("an orc leader");
SetAdjectives( ({ "orc" }) );
SetLong("This orc is very tall.  Standing about seven feet tall, he has to "
        "hunch down inside this tent.  His skin is brown in color and he "
        "has no hair.  He is very impressive standing there looking over "
        "maps and planning strategies.");
SetRace("orc");
SetClass("fighter");
SetCombatAction(30, ({
        "!say Traitors to the cause must die!",
        "!yell GUARDS!",
        "!emote deftly moves about in an attack pattern",
        "!emote swings his sword in very skilled arcs",
}) );
SetAction(10, ({
        "!emote takes a few practice thrusts.",
        "!emote waits for some action.",
        "!emote intently studies maps.",
        "!emote furrows his brow in concentration.",
}) );
SetDie("Orc leader falls down in death.");
SetInventory( ([
        G_OBJ + "leader_armour" : "wear armour",
        G_OBJ + "leader_sword" : "wield sword",
        G_OBJ + "backpack" : "wear backpack",
]) );
SetLevel(8);
SetGender("male");
SetCurrency("cuicui", 25 + random(15));
SetMorality(-600);
}

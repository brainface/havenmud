#include <lib.h>
#include "../argoth.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("footsoldier");
    SetId( ({ "orc footsoldier", "orc", "footsoldier", "soldier"}) );
    SetShort("an orc footsoldier");
    SetLong("This medium sized orc's body ripples with muscles and anger.  "
    "A cold intelligence flares in his eyes, and two enormous, sharp fangs "
    "protrude from his lower jaw.  A large, turned-up nose with flared nostrils "
    "sits on his face.  It is the pure number of these soldiers which account "
    "for the incredible power of the orcish hordes.");
    SetRace("orc");
    SetGender("male");
    SetClass("fighter");
    SetLevel(random(10) + 10);
    SetInventory( ([
    ARGOTH_OBJ + "helm.c" : "wear helm",
    ARGOTH_OBJ + "mace.c" : "wield mace",
    ]) );
    SetAction(5, ({
    "!say I hear we may be moving out soon...",
    }) );
    SetMorality(-10);
}

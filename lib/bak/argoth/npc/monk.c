#include <lib.h>
#include "../argoth.h"

inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("monk of Saahagoth");
    SetId( ({ "monk", "orc" }) );
    SetShort("an Saahagoth monk");
    SetLong("This monk wears a totally blank expression on his face, but "
    "there's something that tells you he would defend his cause to the very "
    "death.");
    SetLevel(18);
    SetRace("orc");
    SetClass("fighter");
    SetGender("male");
    SetInventory( ([
    ARGOTH_OBJ + "cleaver.c" : "wield cleaver",
]) );
    SetFriends( ({ "monk", "priest"}) );
}

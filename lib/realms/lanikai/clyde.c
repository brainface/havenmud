#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("Clyde the cat");
    SetLong("This is a Lanikai's housecat.");
    SetRace("cat");
    SetGender("male");
    SetClass("animal");
    SetLevel(1);
    SetKeyName("Clyde");
    SetId(({"housecat", "cat"}));
}

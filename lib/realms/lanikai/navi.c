#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("Navi the cat");
    SetLong("This is a Illura's housecat.");
    SetRace("cat");
    SetGender("female");
    SetClass("animal");
    SetLevel(1);
    SetKeyName("Navi");
    SetId(({"housecat", "cat"}));
}

#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("a housecat");
    SetLong("This is a plain, grey, housecat.");
    SetRace("cat");
    SetGender("male");
    SetClass("animal");
    SetLevel(1);
    SetKeyName("housecat");
    SetId(({"housecat", "cat"}));
}

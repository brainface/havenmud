#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
  SetShort("a bullfrog");
    SetLong("This is your average bullfrog.");
  SetRace("amphibian");
    SetClass("animal");
    SetLevel(1);
    SetGender("male");
    SetKeyName("bullfrog");
    SetId(({"frog", "bullfrog"}));
}

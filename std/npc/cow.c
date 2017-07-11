#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("a dairy cow");
    SetLong("This is your average milking cow.");
    SetRace("cow");
    SetGender("female");
    SetClass("animal");
    SetKeyName("cow");
    SetId(({"cow"}));
  SetLevel(2);
}

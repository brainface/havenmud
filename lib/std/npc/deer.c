#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("a deer");
    SetLong("This is a plain white tailed deer.");
    SetRace("deer");
    SetClass("animal");
    SetLevel(2);
    SetGender("male");
    SetKeyName("deer");
    SetId(({"deer"}));
}

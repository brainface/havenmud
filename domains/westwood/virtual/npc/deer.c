#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetKeyName("deer");
    SetId(({"deer"})); SetShort("a deer");
    SetLong("This is a plain white tailed deer.");
    SetRace("deer");
    SetClass("animal");
    SetLevel(2);
    SetGender("male");
    
}

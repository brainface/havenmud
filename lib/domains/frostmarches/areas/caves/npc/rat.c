#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("rat");
    SetId( ({"small", "grey"}) );
    SetAdjectives("small");
    SetShort("a small rat");
    SetLong("This is a typical small grey rat.  It looks "
            "underfed and has rather beady eyes.");
    
    SetRace("rodent");
    SetClass("animal");
    SetLevel(1);
    SetGender("male");
}

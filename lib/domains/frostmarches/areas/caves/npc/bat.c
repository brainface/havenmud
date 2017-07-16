#include <lib.h>
#include "../caves.h"

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("bat");
    SetId("bat");
    SetAdjectives("small");
    SetShort("a small bat");
    SetLong("This is a harmless insect eating bat.  He was probably "
            "attracted here by the plethora of insects in this cave.");
    SetRace("bat");
    SetClass("animal");
    SetLevel(1);
    SetGender("male");
}

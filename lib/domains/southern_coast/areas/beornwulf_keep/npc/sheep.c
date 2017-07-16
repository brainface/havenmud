#include <lib.h>
inherit LIB_NPC;

static void create() {
    npc::create();

    SetKeyName("ewe");
    SetId( ({ "small ewe", "ewe", "sheep" }) );
    SetAdjectives( ({ "female", "tiny" }) );
    SetShort("a small ewe");
    SetLong("This tiny female sheep has a ragged and dirty layer of wool.");
    SetRace("sheep");
    SetClass("animal");
    SetLevel(1);
    SetGender("female");
}

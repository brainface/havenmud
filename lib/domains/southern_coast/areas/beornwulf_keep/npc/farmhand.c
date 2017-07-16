#include <lib.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetMorality(50);
    SetKeyName("farmhand");
    SetAdjectives( ({ "young" }) );
    SetId( ({ "young farmhand", "farmhand", "human" }) );
    SetShort("a young farmhand");
    SetLong("This young man is a servant to Lord Beornwulf.  He looks weary "
           "from the constant stress of the orkish attack.");
    SetRace("human");
    SetClass("rogue");
  	SetLevel(2);
    SetGender("male");
}

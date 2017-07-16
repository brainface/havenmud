#include <lib.h>
#include "../argoth.h"

inherit LIB_SENTIENT;
static void create() {
sentient::create();
    SetKeyName("citizen");
    SetId( ({ "argoth citizen", "citizen" }) );
    SetShort("a citizen of Argoth");
    SetLong("This citizen of Argoth is going about his business in the town, "
    "moving without a sound from one building to another.");
    SetLevel(6);
    SetRace("orc");
    SetClass("rogue");
    SetGender("male");
    SetInventory( ([
]) );
    SetWander(15);
}

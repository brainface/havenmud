#include <lib.h>
#include "../camp.h"

inherit LIB_NPC;

static void create() {
    npc::create();

    //descriptions
    SetKeyName("guard");
    SetId( ({ "guard" }) );
    SetShort("a haggard goden");
    SetLong(
      "A goden drunk."
    );
    SetGender("male");

    //vital statistics
    SetClass("rogue");
    SetLevel(15);
    SetRace("goden");

    //miscellaneous
    SetAction(10, ({
      "!yell I'm soooo drunk!",
    }) );
}


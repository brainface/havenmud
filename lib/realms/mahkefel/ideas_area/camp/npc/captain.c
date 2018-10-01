#include <lib.h>
#include "../camp.h"

inherit LIB_NPC;

static void create() {
    npc::create();

    //descriptions
    SetKeyName("captain");
    SetId( ({ "captain", "viking" }) );
    SetShort("a viking captain");
    SetLong(
      "One huge viking captain cat."
    );
    SetGender("female");

    //vital statistics
    SetClass("viking");
    SetLevel(50);
    SetRace("goden");

    //miscellaneous
    SetAction(10, ({
      "!yell walk the plank!",
    }) );
}


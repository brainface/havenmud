#include <lib.h>
#include "../camp.h"

inherit LIB_NPC;

static void create() {
    npc::create();

    //descriptions
    SetKeyName("quartermaster");
    SetId( ({ "quartermaster" }) );
    SetShort("a quartermaster");
    SetLong(
      "Hands out the rum."
    );
    SetGender("male");

    //vital statistics
    SetClass("sailor");
    SetLevel(30);
    SetRace("human");

    //miscellaneous
    SetAction(10, ({
      "!yell I serve rum!",
    }) );
}


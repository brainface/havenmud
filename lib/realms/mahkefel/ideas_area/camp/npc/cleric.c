#include <lib.h>
#include "../camp.h"

inherit LIB_NPC;

static void create() {
    npc::create();

    //descriptions
    SetKeyName("Barion");
    SetId( ({ "barion" }) );
    SetShort("barion the abominable");
    SetLong(
      "A half-orc cleric. Those are fun!"
    );
    SetGender("male");

    //vital statistics
    SetClass("cleric");
    SetReligion("Kylin");
    SetLevel(35);
    SetRace("half-orc");

    //miscellaneous
    SetAction(10, ({
      "!yell Be healed!",
    }) );
}


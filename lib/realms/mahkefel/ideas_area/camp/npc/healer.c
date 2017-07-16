#include <lib.h>
#include "../camp.h"

// contagion source. Has no religion, but looks kylin.
// (because it's, you know, a thing, and so the 
//  healer will treat anyone.

inherit LIB_HEALER;

static void create() {
    ::create();

    //descriptions
    SetKeyName("cleric");
    SetId( ({ "cleric" }) );
    SetShort("a kylin cleric");
    SetLong(
      "A healer. This dude is totally infected."
    );
    SetGender("female");

    //vital statistics
    SetClass("cleric");
    SetClass("fighter");
    SetLevel(40);
    SetRace("half-orc");

    //miscellaneous
    SetAction(10, ({
      "!say I am not infected",
      "!say I'm totally infected guys",
    }) );
}



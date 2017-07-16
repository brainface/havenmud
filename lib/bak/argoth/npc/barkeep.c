#include <lib.h>
#include "../argoth.h"
inherit LIB_BARKEEP;
static void create() {
    barkeep::create();
    SetKeyName("zurth");
    SetId( ({ "zurth", "barkeep", "barkeeper"}) );
    SetShort("Zurth the Barkeep");
    SetLong("Zurth sits behind the counter with his eyes closed, waiting for "
    "business.  From the look of him, however, it looks as though it would be "
    "difficult to surprise him.");
    SetLevel(16);
    SetRace("orc");
    SetClass("fighter");
    SetGender("male");
    SetInventory( ([
]) );
    SetMenuItems( ([
    "orkish grog" : ARGOTH_MENU + "grog.c",
    "dwarf's head stew" : ARGOTH_MENU + "stew.c",
    "sprite wings" : ARGOTH_MENU + "wings.c",
]) );
    SetLocalCurrency("khuca");
}

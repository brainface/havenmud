#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
static void create() {
    room::create();
  SetDomain("Crystal Reaches");
    SetShort("Peddler's Road");
    SetLong("The western end of Peddler's Road is significantly smaller and "
    "has apparently been given much less work and thought than the eastern end "
    "has.  The reason for this is obvious, as the only building here is a "
    "small, plain-looking inn.");
    SetItems( ([
    ({ "peddler's road", "road" }) :
    "The road is narrow and dusty, with several stones missing.",
    ({ "building", "inn" }) :
    "The inn is small and made of a dark wood.  There is a sign in the front "
    "window",
    ({ "sign" }) :
    "The sign reads 'For Sale'",
]) );
    SetExits( ([
    "east" : ARGOTH_ROOM + "rd2.c",
]) );
    SetEnters( ([
    "inn" : ARGOTH_ROOM + "player_inn.c",
    "building" : ARGOTH_ROOM + "player_inn.c",
]) );
    SetObviousExits("east");
    SetSmell( ([
    "default" : "The smell of sawdust and woodchips is easily noticed.",
]) );
    SetListen( ([
    "default" : "Sounds of construction come from all around.",
]) );
    SetInventory( ([
    ARGOTH_NPC + "citizen.c" : 1,
    ARGOTH_NPC + "soldier.c" : 3,
]) );
}

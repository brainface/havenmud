#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
static void create() {
    room::create();
    SetShort("Peddler's Road");
    SetLong("This is the road in Argoth which houses most of the town's "
    "business.  On the far west end of the road is an unowned inn, and the "
    "east end leads to the Armoury, Weaponsmith, and General Store.  The "
    "Argoth Post Office sits just to the north.");
  SetDomain("Crystal Reaches");
    SetItems( ([
    ({ "road" }) :
    "This is the street known as Peddler's Road.  It runs perpendicular to "
    "the main road.",
    ({ "office" }) :
    "The post office is where citizens of Argoth go to send their mail. "
    "It is large building, built out of a dark red brick.",
    ({ "unowned inn", "inn" }) :
    "The inn, a small, black building, can hardly be seen from here.",
    ({ "armoury", "weaponsmith", "general store", "store" }) :
    "The three stores all lie in a row at the end of the street.",
]) );
  SetItemAdjectives( ([
    "office" : ({ "post", "town", "argoth" }),
  ]) );
    SetExits( ([
    "west" : ARGOTH_ROOM + "rd2.c",
    "east" : ARGOTH_ROOM + "rd4.c",
]) );
    SetEnters( ([
    "office" : ARGOTH_ROOM + "p_off.c",
]) );
    SetObviousExits("east, west");
    SetSmell( ([
]) );
    SetListen( ([
    "default" : "The sounds of people moving about the town are everywhere.",
]) );
    SetInventory( ([
    ARGOTH_NPC + "guard.c" : 2,
]) );
}

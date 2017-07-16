#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
static void create() {
    room::create();
  SetDomain("Crystal Reaches");
    SetShort("Peddler's Road");
    SetLong("Peddler's Road comes to an abrupt end here before the door of "
    "General Store.  Two paths lead off towards the Armoury and Weaponsmith."
    "  Back to the west, there are many signs of life.");
    SetItems( ([
    ({ "peddler's road", "road" }) :
    "Peddler's Road runs east and west perpendicular to the main road.",
    ({ "door" }) :
    "The door to the General Store is very large, and made of a very dark "
    "wood.",
    ({ "general store", "store" }) :
    "The General Store is rather small, but well built.  Various goods hang "
    "in the window.",
    ({ "armoury" }) :
    "The armoury is a large building with smoke puffing out of the chimney.",
  ({"weaponsmith", "smithy"}) :
    "The Weaponsmith lies on the right side of the General Store.  A sign "
    "hangs over the door.",
    ({ "sign" }) : 
    "The sign has pictures of various weapons.",
]) );
    SetExits( ([
    "west" : ARGOTH_ROOM + "rd3.c",
]) );
    SetEnters( ([ 
    "armoury" : ARGOTH_ROOM + "armoury.c",
    "weaponsmith" : ARGOTH_ROOM + "weaponsmith.c",
    "store" : ARGOTH_ROOM + "general.c",
    "general store" : ARGOTH_ROOM + "general.c",
]) );
    SetObviousExits("west");
    SetListen( ([
    "default" : "Clanging noises come from both the armoury and the "
    "weaponsmith",
]) );
    SetSmell( ([
    "default" : "The smell of smoke is strong here.",
]) );
    SetInventory( ([
]) );
}

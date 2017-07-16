#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
static void create() {
    room::create();
  SetDomain("Crystal Reaches");
    SetShort("A dirty road");
    SetLong("The road turns quite dirty at this point.  Apparently, the sewer "
    "system is backed up, despite the gargantuan grate that lies to the side "
    "of the road.  The road continues north and south.");
    SetItems( ([
    ({ "dirty road", "road" }) :
    "The road is full of all kinds of slimy wastes.",
    ({ "grate" }) :
    "The grate is huge, and looks as though there is a handle on it for "
    "opening.  What use this could have is a mystery.",
]) );
    SetExits( ([
    "north" : ARGOTH_ROOM + "rd2.c",
    "south" : ARGOTH_ROOM + "rd7.c",
]) );
    SetEnters( ([
    "grate" : ARGOTH_ROOM + "sewer.c",
]) );
    SetObviousExits("north, south");
    SetSmell( ([
    "default" : "There is an overwhelming stench coming from the build up "
    "in waste products that has accumulated here.",
]) );
    SetListen( ([
    "default" : "Strange gurgling and clanging sounds are coming from beneath "
    "the road.",
]) );
    SetInventory( ([
]) );
}

#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
    int PreExit();
static void create() {
    room::create();

    SetShort("the Argoth Gate");
    SetLong("The huge iron gate to the city of Argoth looms ahead, with a "
    "gradually widening cobblestone road leading through it into the city.  "
    "Completed buildings and buildings still under construction can be seen.");
  SetDomain("Crystal Reaches");
    SetItems( ([
    ({ "huge iron gate", "iron gate", "huge gate", "argoth gate", "gate" }) :
    "This gate is made of an incredibly hard and durable dark metal that can "
    "be easily locked in case of an attack.",
    ({ "widening cobblestone road", "cobblestone road", "road" }) :
    "The road continues straight up to the gate, where it becomes three times "
    "as wide and passes through the middle of it.",
    ({ "city of argoth", "city", "argoth" }) :
    "Argoth is an enormous, menacing brute of a city.",
    ({ "completed buildings", "buildings" }) :
    "The buildings are all built of the same dark metal and stone.",
]) );
    SetExits( ([
    "north" : ARGOTH_ROOM + "clearing",
    "south" : ARGOTH_ROOM + "rd2",
]) );
    SetObviousExits("north, south");
    SetSmell( ([
    "default" : "There is a slight smell of smoke coming from the south.",
]) );
    SetListen( ([
    "default" : "The sounds of construction are greater here.",
]) );
    AddExit("north", ARGOTH_ROOM + "clearing.c", (:PreExit :) );
}

 int PreExit() {
    if(!userp(this_player())) return 0;
    return 1;
}

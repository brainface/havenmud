#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetShort("The Argoth Bank");
    SetLong("The Argoth bank is a large fancy building with black marble walls. "
    " In the middle of the main room is a large counter where transactions "
    "take place, and in the back are the offices of bank employees.");
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd7.c",
]) );
    SetObviousExits("out");
  SetDomain("Crystal Reaches");
    SetSmell( ([
    "default" : "The bank smells like money",
]) );
    SetListen( ([
    "default" : "The faint jingling of coins can be heard.",
]) );
    SetClimate("indoors");
    SetInventory( ([
    ARGOTH_NPC + "teller.c" : 1,
]) );
    SetAmbientLight(45);
}

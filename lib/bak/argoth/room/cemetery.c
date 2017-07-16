#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetShort("The Argoth Cemetary");
    SetLong("The Argoth cemetary is one of the most frightening places in "
    "the world, partly due to the enormous statues of demons and other evil "
    "creatures, and partly due to the thick air of death that is suspended"
    "here. Graves are set in lines with little more than a few twigs or  "
    "rocks to let one know that they are there.");
    SetItems( ([
    ({ "argoth cemetary", "cemetary" }) :
    (: GetLong :),
    ({ "statues", "demons", "evil creatures", "creatures" }) :
    "The statues are depictions of the demons of Arrashi legend.",
    ({ "graves", "twigs", "rocks" }) :
    "The graves would be easily overlooked if it were not for the small "
    "branches and rocks that were piled at their heads.",
]) );
  SetDomain("Crystal Reaches");
    SetSmell( ([
    "default" : "The cemetary smells of rot and mud.",
]) );
    SetListen( ([
    "default" : "There is a terrifying silence here.",
]) );
    SetInventory( ([
]) );
    SetNightLight(20);
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd7.c",
]) );
    SetObviousExits("out");
}

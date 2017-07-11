#include <lib.h>
#include "path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a gloomy hallway");
    SetLong("The west side of the room is dark and gloomy like the rest of "
          "the keep, but towards the east the floor goes from stone to "
          "a covering of hay and dirt.");
    SetItems( ([
          ({ "dirt", "hay" }) :
          "Dirt and hay cover the eastern portion of the floor.",
          ({ "stone" }) :
          "The west side of the floor is made of stone.",
          ({ "floor" }) :
          "The floor is made of cold granite, but to the east of the room "
          "it is covered with hay.",
          ({ "west side" }) :
          "The west side of the room is dark and gloomy.",
          ({ "east side" }) :
          "The east side of the room is covered with hay.",
          ]) );
    SetExits( ([
          "west" : BEORN_ROOM + "gatehouse.c",
          "east" : BEORN_ROOM + "stable.c",
          ]) );
    SetObviousExits("west, east");
    SetInventory( ([
           BEORN_NPC + "hsoldier.c" : 1,
           ]) );
    SetClimate("indoors");
    SetAmbientLight(30);
    SetListen( ([
          "default" : "A gentle bleating noise can be heard, as well as the "
          "occasional 'Mooo' ",
]) );
}

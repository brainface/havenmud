#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a path leading to a shrine");
  SetLong("Just to the north of here is the"
          " Tairi Path that leads along the"
          " island. Leading to the south is a"
          " neatly trimmed path that has been"
          " lined with stones of similar shapes"
          " and sizes. An unnatural fog hovers"
          " close to the ground obscuring vision"
          " and making it hard to judge the"
          " distance to the shrine south of here.");
  SetItems( ([
          ({ "path", "tairi path", "stone", "stones"}) :
          "Lined with stones of equal size and shape"
          " this path has obviously been neatly"
          " manicured and cared for. To the north"
          " the Tairi Path is visible.",
          ({ "fog" }) :
          "The fog here is very thick and unnatural.",
          ({ "shrine" }) :
          "To the south the outline of a shrine is"
          " barely visible through the thick fog.",
          ]) );
  SetItemAdjectives( ([
          "path" : ({ "neat", "trimmed", "neatly trimmed"
          }),
          "fog" : ({ "unnatural", "thick" }),
          ]) );
                     
  SetSmell( ([
          "default" : "The brisk odor of a cold wind lingers.",
       ]) );
  SetListen( ([
          "default" : "The sound of distant moaning"
                      " reaches here.",
        ]) );
  SetExits( ([
           "south" : SHRINE_ROOM "room2",
           "north" : "/domains/tairi/virtual/tairi_path/-9,-1",
        ]) );
  SetInventory( ([
        ]) );
}


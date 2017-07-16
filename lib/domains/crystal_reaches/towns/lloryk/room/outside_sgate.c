#include <lib.h>
#include <domains.h>
#include "../path.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a curve in the Lloryk Road");
  SetLong("From here the road continues on to the east and "
     "north. The cobblestone pavings firm up and are much more "
     "well maintained to the north, and a short wooden fence "
     "can be seen which crosses the road in a manner not unlike "
     "a town wall. A makeshift guardpost lies directly in view "
     "of the path.");
  SetListen( ([
    "default" : "The land is peaceful and blissfully unaware of itself.",
    ]) );
  SetSmell( ([
    "default" : "A faint tinge of manure tells the tale of farmland nearby.",
    ]) );
  SetItems( ([ 
    ({ "road",  }) : "This small road is made out of "
                     "nicely laid cobblestones.",
    "wall" : "To the north, a small wooden fence can be seen. "
             "This seems to be the town wall for Lloryk.",
    ({ "gate", "main gate" }) : "There is a small wooden gate "
                                "to the north that enters into Lloryk.",
    "people" : "People are passing in and out of the "
               "gate to work and to get to different places in Kailie.",
    ({ "post", "guardpost" }) : "This is a makeshift guardpost. It is"
                                " made of a few logs stacked to provide"
                                " very little cover.",
     ]) );
  SetExits( ([
      "east"  : CRYSTAL_REACHES_VIRTUAL "llorykroad/0,0",
      "north" : "southgate",      
    ]) );
}


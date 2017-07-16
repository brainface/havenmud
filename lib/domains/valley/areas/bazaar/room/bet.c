/* This is the place for people to bet on the jousting contest. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley"),
  SetShort("a betting booth");
  SetLong("This is a crudely erected booth formed by four walls with "
     "a large window in the east wall. The poorly thatched roof has a "
     "few holes in it and there are several places on the walls that could "
     "use patching. Some healthy grass surrounds the booth, but there "
     "is a trodden patch in front of the window. It appears that one could "
     "make a bet of some sort here. There is another booth to the east, "
     "and there seems to be a large field west of here.");
  SetItems( ([
   ({ "booth" }) : (: GetLong :),
   ({ "east wall", "wall" }) : "This wall has a large window cut out in the center.",
   ({ "four walls", "walls" }) : "These seem to be ordinary walls, except for the east wall.",
   ({ "window" }) : "The window that has been cut out of the east wall is apparently intended for communicating with someone inside the booth.",
   ({ "roof" }) : "It is in desperate need of a repair job.",
   ({ "hole", "holes" }) : "These holes indicate that the booth has been poorly cared for.",
  ({ "healthy grass", "grass" }) : "It covers the ground around the booth and appears to be quite healthy.",
   ({ "trodden patch of grass", "patch", "grass" }) :
    "The grass just in front of the window has been trampled.",
   ({ "field" }) : "This large field is just west of here.", 
  ]) );
  SetItemAdjectives( ([
   "booth" : ({ "crudely", "erected" }),
   "walls" : ({ "four" }),
   "window" : ({ "large" }),
   "roof" : ({ "poorly", "thatched" }),
   "field" : ({ "large" }),
  ]) );
  SetSmell( ([
     "default" : "The smell of food cooking mixes with the smells of live animals.",
  ]) );
  SetListen( ([
     "default" : "You hear shouting and laughter coming from the west.",
  ]) );
  SetExits( ([
     "east" : BAZAAR_ROOM "swing",
     "west" : BAZAAR_ROOM "joust",
     "southeast" : BAZAAR_ROOM "mud",
  ]) );
}

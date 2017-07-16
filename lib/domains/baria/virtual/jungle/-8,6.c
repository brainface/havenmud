/*  The jungle room */
#include <lib.h>
inherit LIB_ROOM;
string DeadDragon();
int PreExit(string);

static void create() {
  room::create();
  SetClimate("tropical");
  SetDomain("Baria");
  SetShort("in a sweltering jungle");
  SetObviousExits("north, east, south, west");
  SetExits( ([
     "north" : "-8,7",
     "west" : "-9,6",
     "east" : "-7,6",
     "south" : "-8,5",
    ]) );
  SetLong("This large open area of the jungle seems to have been "
          "flattened by years of something large lying in place. "
          "In all directions the jungle continues on and deepens "
          "from this clearing to a full fledged jungle.");
  SetSearch( ([
    "default" : (: DeadDragon :),
    ]) );
  SetSmell( ([
    "default" : "The smell here is one of death.",
    ]) );
  SetListen( ([
     "default" : "The sounds of the jungle seem muted here.",
    ]) );
  SetInventory( ([
      ]) );
  }

string DeadDragon() {
  object dragon;

  if (present("lair", this_object())) {
    return "There is a lair here!";
   }
 if (dragon = present("kysanth", this_object())) {
    dragon->eventForce("emote prevents your search.");
    return "You are stopped from searching.";
    }
  AddItem("lair", "This is a hidden lair!");
  AddEnter("lair", "/domains/baria/areas/jungle/lair", (: PreExit :) );
  return "You find the entrance to a hidden lair.";
  }

int PreExit(string dir) {
  if (present("dragon", this_object())) {
  present("dragon", this_object())->eventForce("emote guards the lair.");
  return 0;
  }
  return 1;
  }

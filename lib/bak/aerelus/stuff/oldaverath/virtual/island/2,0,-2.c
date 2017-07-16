#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(2,0,-2);

  SetLong("This part of the tunnel is a bit darker than the rest; the "
     "torches are missing. The dirty walls are covered in slime "
     "and muck from the passage of sewage through the tunnels. The floor "
     "carries a small stream of muck and other debris into the next "
     "tunnels north and west of here.");
  SetItems( ([
     ({"torch","torches"}) : "There are no torches on the walls, they "
       "appear to be missing.",
     ({"wall","walls"}) : "The curved walls are constructed of a dark "
       "stone and are covered with all sorts of muck from the sewage.",
     ({"debris","sewage","stream","muck","slime"}) : "this dark colored "
       "muck and sewage covers the walls and floor and runs in a small "
       "stream towards the other passages.",
     ({"floor","ground"}) : "The floor is dirty and a small stream of "
       "sewage runs through the middle of it.",
     ]) );
  RemoveExit("east");
  RemoveExit("south");
}

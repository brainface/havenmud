#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(2,1,-2);

  SetLong("Dark and foreboding, this tunnel is darker than the rest. "
     "The curved stone walls are made of dark stone and are "
     "lacking the few torches that adorn the rest of the tunnels. The "
     "darkness continues to the east and south.");
  SetItems( ([
     ({"torch","torches"}) : "There are no torches on the walls, they "
       "are missing.",
     ({"wall","walls"}) : "The curved walls are constructed of a dark "
       "stone and are covered with all sorts of muck from the sewage.",
     ({"muck","slime"}) : "this dark colored muck and sewage covers the "
       "walls and floor.",
     ({"floor","ground"}) : "The floor is filthy.",
     ]) );
  RemoveExit("west");
  RemoveExit("north");

}

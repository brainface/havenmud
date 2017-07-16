#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(3,1,-2);

  SetLong("The tunnel ends here abruptly with a wall of stones that look "
     "like they are smaller than the ones that make up the rest of the "
     "tunnels. A small torch dimly lights this end of the sewers, and "
     "shows the passage back to the west. The northern wall has a "
     "rather large hole carved into it.");
  SetItems( ([
     ({"wall","walls"}) : "The curved walls are constructed of a dark "
       "stone and are covered with all sorts of muck from the sewage. "
     "The eastern wall looks newly constructed and the northern wall "
     "has a hole cut into it.",
     ({"hole"}) : "This rather large hole has been dug into the northern "
       "wall and looks large enough for a small human to enter.",
     ({"torch"}) : "This is a small wooden torch that gives off barely "
       "enough light to see your hands in front of your face.",
     ({"floor","ground"}) : "The floor is filthy, covered with muck and "
       "sewage and carries a small stream of slime into the other tunnels "
       "of the sewer.",
     ]) );
  SetEnters( ([
     "hole" : AVERATH_GOBLIN "ghovel2",
     ]) );
  RemoveExit("north");
  RemoveExit("east");
  RemoveExit("south");
   SetAmbientLight(26);
}

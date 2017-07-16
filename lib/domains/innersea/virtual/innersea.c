#include <domains.h>
#include <lib.h>
inherit LIB_ROOM;

static void create(int x, int y) {
  string n, s, e, w, ne, nw, sw, se;
  ::create();
  SetShort("the Inner Sea");
  SetProperty("ocean", 1);
  SetClimate("temperate");
  SetLong("The waves of blue drift lazily over their course, carried along by currents "
          "and winds that a trained seaman can read as surely as a book. The blue sky "
          "is beautiful here away from town. The blue sea stretches out endlessly in "
          "every direction.");
  SetSmell( ([ 
    "default" : "The air is crisp and clean, with only a slightly salty smell.",
    ]) );
  SetListen( ([
    "default" : "The sea is quiet except for the occasional howl of a bird.",
    ]) );
  n = INNERSEA_VIRTUAL "innersea/" + x + "," + (y + 1);
  s = INNERSEA_VIRTUAL "innersea/" + x + "," + (y - 1);
  if (y == 50) {
   n = SOUTHERN_COAST_TOWNS "haven/room/wharf";
    }
  if (y == -50) {
    s = AVERATH_VIRTUAL "island/-2,5,0";
  }
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
}

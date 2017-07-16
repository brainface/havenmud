#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

static void create() {
  ::create(1,-1,-1);
  AddExit("up", AVERATH_ISLAND "1,-1,0");
  SetLong("Dark and foreboding, the tunnel leads off to the west. The "
     "curved walls of the tunnel are wet and slimy, and the ceiling is "
     "high enough in the center to allow a human of average stature to "
     "stand upright. Created from thick stones, the tunnel can give even "
     "the most fearless an occasional feeling of claustrophobia. The muck "
     "covered floor indicates that the tunnel is a part of a sewer system. "
     "There is a small sewer grate leading back to town.");
  SetItems( ([
     ({"wall","walls","stone","stones","ceiling"}) : "The dark stone walls "
       "are covered with a thin layer of a greenish, moist slime.",
     ({"grate"}) : "This is a sewer grate leading up.",
     ({"muck","floor"}) : "The muck on the floor seems to become greater "
       "to the west, forming a sort of river that runs through the "
       "passages.",
    ]) );
  RemoveExit("east");
  RemoveExit("north");
  RemoveExit("south");
}

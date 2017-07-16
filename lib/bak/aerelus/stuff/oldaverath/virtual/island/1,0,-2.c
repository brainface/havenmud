#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(1,0,-2);

  SetLong("Dark and foreboding, the tunnel leads off to the south, east "
     "and west. The curved walls of the tunnel are wet and slimy, and the "
     "ceiling is high enough in the center to allow a human of average "
     "stature to stand upright. Created from thick concrete, the tunnel "
     "can give even the most fearless an occasional feeling of claustrophobia. "
     "The muck covered floor indicates that the tunnel is a part of a "
     "sewer system.");
  RemoveExit("north");
}

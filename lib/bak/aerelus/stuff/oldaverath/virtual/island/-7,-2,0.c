#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(-7,-2,0);

  SetShort("at the base of a mountain");
  SetLong("The grassy plains of Averath lead out from here, displaying "
     "their beauty for all the world to see. To the south lies a rather "
     "large mountain that is impassable from here. Small footprints of "
     "animals lead in all different directions from here.");
  SetItems( ([
     ({"plains"}) : "The plains stretch out as far as the eye can see.",
     ({"mountain"}) : "This large mountain blocks the way to the south. "
       "The sides of the mountain are covered with lush green plants and "
       "trees. From this angle there is no visible path up it's side and "
       "the top is hidden by a few wispy clouds.",
     ({"footprint","footprints"}) : "These footprints are obviously made "
       "by animals who have wandered through here.",
     ]) );
  SetItemAdjectives( ([
     "plains" : ({"grassy"}),
     "mountain" : ({"large"}),
     "footprint" : ({"small"}),
     ]) );
  RemoveExit("south");
}

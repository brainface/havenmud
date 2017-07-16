#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(-5,-6,0);

  SetShort("near a large mountain");
  SetLong("The beautiful plains of Averath spread out from here as far "
     "as the eye can see. Northwest of here a large mountain can be "
     "seen. Small footprints of animals lead in all directions from here.");
  SetItems( ([
     ({"plains"}) : "The plains stretch out as far as the eye can see.",
     ({"mountain"}) : "This large mountain blocks the way to the "
       "northwest. The sides of the mountain are covered with lush "
       "green plants and trees. The top is hidden by a few wispy clouds.",
     ({"footprint","footprints"}) : "These footprints are obviously made "
       "by animals who have wandered through here.",
     ]) );
  SetItemAdjectives( ([
     "plains" : ({"grassy","beautiful"}),
     "mountain" : ({"large"}),
     "footprint" : ({"small"}),
     ]) );
}

#include <lib.h>
inherit LIB_ROOM;
#include "westwood.h"

static int XPosition, YPosition;

static void create(int x, int y) {
   string long;
   SetNoClean(1);
   room::create();
   XPosition = x;
   YPosition = y;
   SetShort("the Soleil Road");
   long = "Trees bend over the road, creating light shadows "
             "on the dirt.  Foliage clutters up the spaces "
             "between the trees.";
   SetItems( ([
               ({ "Soleil Road","road","westwood" }) :
                  (: GetLong :),
               ({ "bending trees","tree","trees" }) :
                  "The trees are mostly deciduous, with a few "
                  "coniferous trees sprinkled throughout.  "
                  "Brush fills the area between trees.",
               ({ "cluttering brush","brush" }) :
                  "The brush is green and healthy.  It fills "
                  "the area between the trees.",
            ]) );
   SetItemAdjectives( ([
                  "road" : ({ "soleil" }),
                  "trees" : ({ "bending" }),
                  "brush" : ({ "cluttering"}),
               ]) );
   if(y == 0) {
      AddExit("south", START);
      AddExit("northwest", VIRTUAL + "soleilroad/" + (x+1) + "," + (y+1));
      long += "  The Soleil Road ends to the south, but continues "
                 "to the northeast.";
   }
   else if(y==20) {
      AddExit("northwest", VIRTUAL + "westwood/0,0");
      AddExit("southeast", VIRTUAL + "soleilroad/" + (x-1) + "," + (y-1));
   }
   else {
      AddExit("northwest", VIRTUAL + "soleilroad/" + (x+1) + "," + (y+1));
      AddExit("southeast", VIRTUAL + "soleilroad/" + (x-1) + "," + (y-1));
      long += "  The Soleil Road goes northwest and southeast.";
   }
   SetLong(long);
}

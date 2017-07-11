#include <lib.h>
#include <vendor_types.h>
inherit LIB_ROOM;
#include "../castle.h"
string WallSearch();

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("at the altar");
   SetLong("Stone steps lead down off this slightly raised area, of which "
           "the altar is center stage.  The altar is rectangular, like a "
           "box, with a plain embroidered cloth lying across it.  "
           "There are candles at each of its corners, and a few fresh "
           "flowers are lying across.  Torches are spaced out along "
           "the stone walls, and more dried flowers have been weaved into "
           "wreaths to be hung as well.");
   SetItems( ([
                ({ "stone walls","stone wall","walls","wall","torches",
                   "torches","dried flowers","dried flower","flowers",
                   "flower","wreaths","wreath","lace" }) :
                   "The stone walls are a simple gray color, which "
                   "is livened up with the colorful wreaths of "
                   "dried flowers.  Torches provide light, spaced out "
                   "evenly across the walls, seperated from the "
                   "wreaths so as to avoid fires. The torches flicker "
                   "as if a breeze was coming from behind the walls.",
                ({ "rectangular altar","altar","plain cloth",
                   "plain embroidered cloth","cloth",
                   "embroidered cloth","candles","candles","boughs",
                   "fresh flowers","fresh flower","flower","flower" }) :
                   "The altar is simple, with lightly scented candles "
                   "at each end and fresh flowers across its center.  "
                   "It appears to be open in the back, allowing one "
                   "to the enter it.",
                ({ "slightly raised area","raised area","area",
                   "chapel" }) :
                   (: GetLong :),
                ({ "stone steps","steps","stone step","step" }) :
                   "The steps lead off to the north, into the rest "
                   "of the chapel.",
           ]) );
   SetSmell( ([
                "candle" : "A light vanilla and rose scent comes from "
                   "the candles.",
                "flowers" : "The stronger smells of fresh roses come "
                   "from the fresh flowers on the altar, and "
                   "a lighter scent comes from those on the walls, "
                   "mixed in with a myriad of other flower types.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/chapel",
           ]) );
   SetEnters( ([
                 "altar" : VC_ROOM + "/altar_in",
            ]) );
SetSearch( ([
             "wall" : (: WallSearch :),
             "walls" : (: WallSearch :),
             ]) );
}


string WallSearch() {
  if (GetExit("south")) {
    return "The area has already been searched to reveal an exit to the south.";
    }
  AddExit("south", VC_ROOM + "/c_stairs");
  return "You find an exit to the south!";
  }

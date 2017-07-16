#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

 static void create() {
   room::create();
  SetShort("a connecting hallway");
   SetDayLong("This room is brightly lit by candles all around, and extra "
        "light comes from downstairs. This hall connects two doorways "
         "that protrude from the crumbling walls and a fragile-looking "
        "staircase that leads up to the annex of the lodge. Other than "
         "the obvious, this room seems to have nothing of worth in it.");
  SetNightLong("This room is brightly lit by candles all around. "
        "This hall connects two doorways "
         "that protrude from the crumbling walls and a fragile-looking "
        "staircase that leads up to the annex of the lodge. Other than "
         "the obvious, this room seems to have nothing of worth in it.");
  SetAmbientLight(25);
   SetClimate("indoors");
   SetItems( ([
         ({"room","hallway","hall"}) : (:GetLong:),
         ({"candle","candles","light"}) : "These candles are burnt down "
         "to the last of the wick.  For such little fuel to burn on, these candles "
         "sure do give off an intense stream of light.",
         ({"door","doorway","doorways","doors"}) : "Unlike the other "
      "doors in this lodge, these doors pertrude from the walls instead of "
         "being indented into them.  They are fairly large size, enough to "
     "fit in any sort of being. They are made of thick wood with a clan-symbol "
         "embroydered in gold. One door is ripped off the hinges.", 
      ({"stairs","staircase"}) : "These stairs look very fragile.  It is quite dark "
         "up there but, oddly, another door can vividly be made out.",
         ({"wall","walls"}) : "The designs painted on these walls were once "
         "pictures of a certain clan.  The walls are ancient and crumbled, "
         "making the paintings no more than a faded image.",
   ]) );
  SetItemAdjectives( ([ 
         "candle" : ({"burnt"}),
         "door" : ({"large"}),
         "stairs" : ({"fragile"}),
   ]) );
   SetExits( ([
      "up" : L_ROOM + "staircase.c",
      "east" : L_ROOM + "bedroom1.c",
      "west" : L_ROOM + "bedroom2.c",
      "down" : L_ROOM + "mainfloor.c",
   ]) );
   SetSmell( ([ 
         "default" : "The aroma of burnt, melted, wax is here.",
   ]) );
   SetListen( ([
         "default" : "Blowing winds sound off in the distance.",
   ]) );
}

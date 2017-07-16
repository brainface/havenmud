#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 
  SetAmbientLight(15);
  SetClimate("indoors"); 
  SetShort("a connecting hallway");
  SetLong(
     "This hallway branches off into rooms on either side. "
     "The crumbling stone walls are covered in dusty tapestries, and "
     "there are small niches carved into them which hold candles. The "
     "room is dimly lit, casting odd shadows on the walls and floor. "
     );
  SetSmell( ([ 
     "default" : "The aroma of burnt, melted, wax is here.",
     ]) );
  SetListen( ([
     "default" : "Blowing winds sound off in the distance.",
     ]) );
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

}

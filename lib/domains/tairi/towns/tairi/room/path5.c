#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along the Chrysanthemum Path");
  SetExits( ([
    "east" : "path6",
    "west" : "cemetery",
    ]) );
  SetLong("The Chrysanthemum Path leads east and west from here. "
          "To the west is the quiet glade used for funerals, "
          "while to the east is the center of town. The path "
          "is lined with lightly scented purple flowers.");
  SetItems( ([
    ({ "flower", "flowers", "chrysanthemums", "chrysanthemum" }) :
         "The small purple flowers are chrysanthemums.",
    "path" : "The dirt beaten Chrysanthemums path is lined "
    	       "with purple flowers. The path heads east toward "
    	       "the center of Tairi and west towards the funeral "
    	       "glade.",
    "glade" : "The funeral glade of Tairi is west along the "
    	        "flower lined path.",
    ({ "center", "town", "tairi" }) :
    	       "The center of Tairi is east along this dirt beaten "
    	       "path.",
    ]) );
  SetItemAdjectives( ([
    "flower" : ({ "purple", "small", "scented" }),
    "path"   : ({ "dirt", "beaten" }),
    "glade"  : ({ "funeral", "quiet" }),
    "center" : ({ "town", "tairi" }),
    ]) );
  SetSmell( ([
    "default" : "The scent of the purple flowers is light and airy.",
    "flower" :
         "The flowers have a faint but pleasant smell to them.",
    ]) );
  SetListen( ([
    "default" : "The town is peaceful and quiet.",
    ]) );
 
  
}

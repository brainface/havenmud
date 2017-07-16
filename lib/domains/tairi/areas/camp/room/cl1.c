#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
  SetProperty("no steal", 1);
  SetShort("a peaceful clearing");
  SetExits( ([
    "east" : CAMP_ROOM + "cl2",
    ]) );
  SetListen( ([ 
    "default" : "The sounds of life drift in from the south.",
    ]) );
  SetNightLight(10);
  SetDayLong("The camp seems to end here, with this being an atypically "
            "calm place to be.  The sky overhead is peaceful and bright, "
            "and the cares of the world seem somehow unimportant here.");
  SetNightLong("The stars twinkle overhead in a bright display, seeming "
               "to spread calm and peace over the area.  This clearing "
               "seems to be a safe place to hide.");
}

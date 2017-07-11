#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate field");
  SetClimate("sub-arctic");
  SetDayLong("The sunlight does nothing to warm this patch of "
             "barren wasteland.  The ruins of the graveyard are "
             "more apparent here in the small chips of stone and "
             "block that were once large headstones.  To the north "
             "and west, there is a large structure.");
  SetNightLong("The starlight does nothing to soften this patch of "
             "barren wasteland.  The ruins of the graveyard are "
             "more apparent here in the small chips of stone and "
             "block that were once large headstones.  To the north "
             "and west, there is a large structure.");
  SetItems( ([
     ({ "chip", "chips" }) : "Once part of headstones, these have "
                             "worn to nearly nothing.",
    "structure" : "The structure is some kind of crypt.",
    ]) );
  SetSmell( ([
    "default" : "The smell of death permeates the air.",
    ]) );
  SetListen( ([
      "default" : "The silence of the dead is overpowering.",
    ]) );
  SetDayLight(-10);
  SetExits( ([
     "north" : NEWBIE_ROOM + "/field8",
     "east"  : NEWBIE_ROOM + "/field10",
     "west"  : NEWBIE_ROOM + "/field4",
     ]) );
  }

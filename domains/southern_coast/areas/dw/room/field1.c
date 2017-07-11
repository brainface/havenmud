#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate field");
  SetClimate("sub-arctic");
  SetDayLong("The field opens a bit here, giving a view of a small "
             "ruin to the north and east. The ground is still somewhat "
             "soft, but easily navigable.  To the northeast is some kind "
             "of structure.");
  SetNightLong("The quiet foreboding of the cemetery is compounded here, "
               "with a dark, pathless patch of ruin which stretches "
               "into the immediate distance. To the northeast, there "
               "is a structure of some kind.");
  SetListen( ([
    "default" : "There is a chilling silence to this area.",
    ]) );
  SetSmell( ([
    "default" : "The fetid smell of old death hangs in the area.",
    ]) );
  SetItems( ([
    "structure" : "This is some kind of crypt in this distance.",
    ({ "ruin", "ruins" }) : "This is an old graveyard, by the looks.",
    ]) );
  SetDayLight(-10);
  SetExits( ([
     "north" : NEWBIE_ROOM + "/field2",
     "east"  : NEWBIE_ROOM + "/field4",
     ]) );
  }

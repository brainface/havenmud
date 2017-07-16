//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

int CheckKeryth();

static void create() {
  room::create();
  SetShort("Along a road in Keryth");
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetLong("A narrow path winding through the snow binds the different "
          "buildings in Keryth together.  It continues north and back "
          "southeast.  Standing to the west side of the path is the "
          "Keryth post office, and to the east is the town hall.");
  SetItems( ([
    ({ "narrow path", "path", "town"}) : (: GetLong :), 
    ({ "snowy white backround", "snowdrifts", "snow", "white backround",
       "backround", "blurred backround", "snowy backround"}) :
       "Snowdrifts abound in the town that is ever encompassed by winter's "
       "cold touch. It creates a white, blurred backround which sharply "
       "contrasts with any surrounding buildings.",
    ({ "post office", "post", "office", "building", "buildings",
       "simple wooden building", "wooden building"}) :
       "The post office is a simple wooden building standing in the snow.",
    ({ "town hall", "hall", "building", "a-frame", "building", "buildings"}) :
       "The town hall is a sturdy looking building. It's large A-frame "
       "structure gives it a very imposing image against the white snowy "
       "backround.",
  ]) );
  SetItemAdjectives( ([
    "path" : ({ "narrow" }),
    "background" : ({ "snowy", "white", "blurred" }),
  ]) );
  SetExits( ([ "north" : K_ROOM + "/road2" ]) );
  SetEnters( ([
    "post office" : K_ROOM + "/office",
    "town hall" : K_ROOM + "/townhall"
  ]) );
  SetListen( ([ "default" : "A cold wind whistles here." ]) );
  AddExit("southeast", K_ROOM + "/trail1", (: CheckKeryth :) );
}

int CheckKeryth() {
  if (this_player()->GetProperty("KerythWander"))
    return 0;
  return 1;
}

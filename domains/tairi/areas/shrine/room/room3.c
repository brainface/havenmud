
#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at the fountain");
  SetLong("A circular clearing of trees here"
          " present a neatly cropped serenity"
          " garden with a fountain in the middle."
          " The path loops around the fountain and"
          " heads back towards the east. The trees"
          " have all been neatly cropped to provide"
          " the most aesthetically pleasing environment.");
  SetItems( ([
          ({ "path", "tairi path", "stone", "stones"}) :
          "Lined with stones of equal size and shape"
          " this path has obviously been neatly"
          " manicured and cared for. It loops"
          " around the fountain and returns to"
          " the east.",
          ({ "trees", "tree" }) :
          "The trees have been neatly trimmed"
          " and are arranged in a nearly perfect"
          " circular pattern.",
                   ]) );
  SetItemAdjectives( ([
          "path" : ({ "neat", "trimmed", "neatly trimmed"
          }),
          "trees" : ({ "trimmed", "neat" }),
          ]) );                 
  SetSmell( ([
          "default" : "The brisk odor of a cold wind lingers.",
       ]) );
  SetListen( ([
          "default" : "The sound of distant moaning"
                      " reaches here.",
        ]) );
  SetExits( ([
           "east" : SHRINE_ROOM "room2",
        ]) );
  SetInventory( ([
           SHRINE_OBJ "fountain" : 1,
        ]) );
}

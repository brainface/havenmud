/*  Level #1 - Cavern #1 - Section #1  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong ("This is a small cavern.  It is rather narrow, but is long enough "
           "that you cannot see the end of it.  The ceiling rises to a "
           "a considerable height where stalactites and stalagmites are "
           "growing.  Some have even grown together into a great column from "
           "floor to ceiling.  The sight gives the cavern a certain ancient, "
           "yet ageless quality.");

  SetSmell( ([
    "default"  :  "There is the distinct smell of the limestone rock that "
                  "makes up the caverns here.",
  ]) );

  SetListen( ([
    "default"  :  "The sound of water dripping as they work at their endless "
                  "task of building the rock formations is joined with that "
                  "of a fluttering sound from the north.",
  ]) );

  SetExits( ([
    "north"      :  ROOMLV1 + "/cave1b",
    "southwest"  :  ROOMLV1 + "/path1",
  ]) );
  SetObviousExits("north, southwest");

  SetItems( ([
    ({ "small cavern", "cavern" })  :  (: GetLong :),
    ({ "ceiling" })  :
       "The ceiling rises to great heights here, and the stalactites that "
       "hang there throw shadows around the cavern to veil it in darkness and "
       "mystery.",
    ({ "stalagmite", "stalagmites", "stalactite", "stalactites", "column",
       "great column", "columns", "great columns" })  :
       "These rock formations give the cavern an ancient, yet ageless "
       "quality.  The sheer size difference of the huge and really small "
       "formations shows the timelessness of the place.",
    ({ "floor", "ground" })  :
       "The floor is alive with bugs of all types and then some.",
    ({ "bugs", "bug", "living bugs", "living bug", "moving bugs", "moving bug",
       })  :
       "Bugs cover the floor in a blanket of living, moving ground.  Bugs "
       "of all shapes and sizes are to be found here.",
    ({ "shadows", "shadow" })  :
       "The shadows add a sense of depth to the cavern, aside from adding to "
       "the overall dark aura of the cavern it provides a place of mystery "
       "and intrigue.",
  ]) );

SetInventory( ([ NPCS + "/bat" : 1, ]) );
}

/*  Level #2 - Cavern #2 - Room #1  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong("In this section of the cavern there is a steep path that leads "
          "upwards.  Your sight to the path is blocked a ways up where the "
          "stalactites and great columns of rock soon block your sight to "
          "it.  To the other directions around you these rock formations soon "
          "block your sight in all directions making the cavern look "
          "untouched for years.");

  SetSmell( ([
    "default"  :  "The smell of wet limestone is prevalent here.",
  ]) );

  SetListen( ([
    "default"  :  "There is a leather flapping echoing around the cavern.",
  ]) );

  SetExits( ([
    "up"         :  ROOMLV1 + "/downtolv2",
    "east"       :  ROOMLV2 + "/cave2b",
    "south"      :  ROOMLV2 + "/cave2c",
    "southeast"  :  ROOMLV2 + "/cave2d",
  ]) );
  SetObviousExits("up, east, south, southeast");

  SetItems( ([
    ({ "small cavern", "cavern" })  :  (: GetLong :),
    ({ "steep path", "path" })  :
       "The steep path leading upwards is soon blocked from your sight by the "
       "rock formations that are overly prevalent in this cavern.",
    ({ "stalactites", "stalactite", "stalagmites", "stalagmite", "columns",
       "great column", "great columns", "column", "rock formations",
       "formation", "formations", "rock formation" })  :
       "These ancient rock formations are still being formed by the water "
       "that is constantly seeping in though the ceiling.  The size of some "
       "of the formations shows just how ancient the cavern really is.  "
       "While the smaller ones give the cavern an ageless look.",
    ({ "water", "ceiling" })  :
       "Water seeps through the ceiling on it's way to work at creating the "
       "rock formations that are extremely prevalent in this cavern.",
  ]) );

  SetInventory( ([ NPCS + "/bat" : 1, ]) );
}

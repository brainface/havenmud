
#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing of trees");
  SetLong("Trees of various types cirlce the area here"
          " with the only visible exit being north."
          " The immediate area is filled with brown,"
          " dead grass and plant life. A dense"
          " miasma seems to originate from here.");
  SetItems( ([
          ({ "tree", "trees", "grass", "plants"}) :
          "The trees that circle this area are the"
          " only visible signs of living vegetation."
          " The grass and plants in the clearing seem"
          " to have died long ago.",
          ({ "fog" }) :
          "The fog here is very thick and unnatural."
          " It seems to originate from this area.",
          ]) );
  SetItemAdjectives( ([
          "grass" : ({ "dead", "brown" }),
          "plants" : ({ "dead", "brown" }),
          "fog" : ({ "dense", "unnatural" }),
          ]) );                 
  SetSmell( ([
          "default" : "The coarse smell of death arrives from the south.",
          ]) );
  SetListen( ([
          "default" : "The sound of distant moaning"
                      " reaches here.",
          ]) );
  SetExits( ([
           "north" : SHRINE_ROOM "room14",
          ]) );
  SetInventory( ([
           SHRINE_NPC "necro" : 1,
           SHRINE_NPC "zombie_guard" : 2,
          ]) );

}

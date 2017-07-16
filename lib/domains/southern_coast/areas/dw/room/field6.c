#include <lib.h>
#include "../newbie.h"
#define WORLD_EXIT  SOUTHERN_COAST_TOWNS "haven/room/cemetery"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetShort("the Old Cemetery");
  SetClimate("sub-arctic");
  SetLong("To the north, the new cemetery sits as a forlorn reminder of death "
          "and the meanings of life. Further north still is the rear entrance "
          "to the local church. Off to the south, a small structure rises in "
          "the center of the field. Scattered around the field are headstones "
          "of people long since dead and forgotten.");
  SetItems( ([
    "structure" : "The structure is an old crypt.",
    ({ "headstone", "headstones" }) : "The headstones are difficult to read.",
    "church" : "The safety of the church looms to the north.",       
    ]) );
  SetSmell( ([
    "default" : "A smell of rot hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "The silence is appalling.",
    ]) );
  SetInventory( ([
    NEWBIE_NPC + "/ghoul" : 1,
   ]) );
  SetDayLight(-10);
  SetExits( ([
     "south" : NEWBIE_ROOM + "/field5",
     "east"  : NEWBIE_ROOM + "/field9",
     "west"  : NEWBIE_ROOM + "/field3",
     ]) );
  AddExit("north", WORLD_EXIT, (: PreExit :) );
  }

int PreExit(string dir) {
  if (this_player()->GetProperty("cemetary npc")) return 0;
  return 1;
 }

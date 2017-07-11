/*  Attachment to Ranquests Ruins Area */
#include <lib.h>
#include <domains.h>
#define RANQUEST_RUINS 1
#define RUINS_DIRECTION ({ "east", FROSTMARCHES_AREAS+"underkeep/room/scree" })
inherit FROSTMARCHES_VIRTUAL+"frostmarchrd";

static void create(int x, int y) {
  ::create(0, 12);
  SetExits( ([
      "north" : "0,13",
      "south" : "0,11",
    ]) );
  if (RANQUEST_RUINS) {
    SetLong( GetLong() +
       "There is a large gaping hole in the ground to the east.");
    AddExit(RUINS_DIRECTION[0], RUINS_DIRECTION[1]);
    SetObviousExits("north, south, east");
    }
 }


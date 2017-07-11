/*  Attachment to Gabriel's Tower area */
//Space added in SetLong to add to the virtual room SetLong
#include <lib.h>
#include <domains.h>
#define GABRIEL_TOWER 1
#define TOWER_DIRECTION ({ "west", FROSTMARCHES_AREAS+"vergoth/room/entrypath" })
inherit FROSTMARCHES_VIRTUAL+"durgorothroad";

static void create(int x, int y) {
  ::create(-10, 10);
  SetExits( ([
      "north" : "-10,11",
      "southeast" : "-9,9",
    ]) );
  if (GABRIEL_TOWER) {
    SetLong( GetLong() +
       " There seems to be a large tower to the west.");
    AddExit(TOWER_DIRECTION[0], TOWER_DIRECTION[1]);
    SetObviousExits("north, southeast, west");
    }
 }

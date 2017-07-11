/*  Connection to Oil ocean */
#include <lib.h>
#include <domains.h>

inherit FROSTMARCHES_VIRTUAL+"frostmarchrd";

static void create(int x, int y) {
  ::create(0, -3);
  SetExits( ([
      "north" : "0,-2",
      "south" : "0,-4",
    ]) );
  SetLong( GetLong() +
    "A ragged trail leads off to the west.");
  SetSmell("A faintly noxious, chemical smell wafts follows a breeze from the west.");
  AddExit("west", FROSTMARCHES_AREAS+"oil_ocean/room/k5");
 }

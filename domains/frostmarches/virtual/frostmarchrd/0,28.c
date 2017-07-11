/*  Attachment to Elasandrias Faerie Kingdom */
#include <lib.h>
#include <domains.h>
#define ELASANDRIA_FAERIE 1
#define FAERIE_DIRECTION ({ "west", FROSTMARCHES_AREAS+"kingdom/rooms/kingdom21" })
inherit FROSTMARCHES_VIRTUAL+"frostmarchrd";

static void create(int x, int y) {
  ::create(0, 28);
  SetExits( ([
      "north" : "0,29",
      "south" : "0,27",
    ]) );
  if (ELASANDRIA_FAERIE) {
    SetLong( GetLong() +
       "There appears to be a small forest to the west.");
    AddExit(FAERIE_DIRECTION[0], FAERIE_DIRECTION[1]);
    SetObviousExits("north, south, west");
    }
 }


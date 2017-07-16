/*  The attachment room for Arathorn's area */
#include <lib.h>
#include <domains.h>
#define ARATHORN 1
#define BEORNWULF_ROOM SOUTHERN_COAST_AREAS + "beornwulf_keep/room/road"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetShort("along the Haven Road");
  SetExits( ([
     "west" : SOUTHERN_COAST_VIRTUAL + "havenroad/-13,0",
     "east" : SOUTHERN_COAST_VIRTUAL + "havenroad/-11,0",
    ]) );
  AddExit("south", BEORNWULF_ROOM, (: PreExit :) );
  SetLong("Along the Haven Road, not much is of note. To the south lie the "
          "lands of Beornwulf, Lord Knight of Haven Town. His keep is a "
          "distant shadow on the edge of human eyesight. To the east and "
          "west the road continues as far as the eye can see.");
  SetListen( ([
  "default" : "The sounds of battle can be heard to the south.",
    ]) );
  SetSmell( ([
     "default" : "The smell of burnt carnage carries on the air.",
    ]) );
 }

int PreExit(string south) {
   if (ARATHORN) {
      return 1;
     }
  else {
     message("system","You are prevented from going south.",this_player());
     return 0;
    }
  }

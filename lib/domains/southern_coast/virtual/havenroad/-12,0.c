/*  The attachment room for Arathorn's area */
// mahk 2018: added items, changed short
#include <lib.h>
#include <domains.h>
#define ARATHORN 1
#define BEORNWULF_ROOM SOUTHERN_COAST_AREAS + "beornwulf_keep/room/road"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetShort("along Havenroad far north of a keep");
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
  SetItems( ([
    ({"keep"}) : "Almost lost in the smoke and mist, the massive stone keep "
      "looms over the lands to the south.",
    ({"lands", "land" }) : "Fields and farms cover the plains under the "
      "watchful keep. Ominous plumes of smoke rise here and there amidst the "
      "fields.",
    ({"field","field","farm","farms", "smoke", "plume","plumes"}): 
      "It's hard to tell from here if the smoke rises from distant campfires "
      "or burning farms.",
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

#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("south of the Shire's northern gate");
  SetExits( ([
     "north" : LLORYK + "room/northgate",
     "south" : LLORYK +"room/uh2",
      ]) );
  SetLong("The road continues to the north and south from here. "
          "To the north, the Shire's boundries are plainly marked "
          "by a short wooden fence, serving to act as a town gate. "
          "To the south, the road leads on into the heart of the "
          "Shire, passing many buildings of note. Rolling hills "
          "spread out to the west where the Shire's farms grow "
          "the food to feed the village. To the east, the Crystal "
          "Reaches rise into the sky."
    );
  SetItems( ([ 
    ({ "fence", "gate" }) : "The low wooden fence is not a serious "
              "barrier here to the north, but merely a boundry marker.",
    ({ "hill", "hills" }) : "The hills provide excellent farming.",
    ({ "mountains", "reaches" }) : "The Crystal Reaches tower against "
              "the eastern horizon.",
    ]) );                
  SetItemAdjectives( ([
    "fence" : ({ "short", "wooden", }),
    "reaches" : ({ "crystal", }),
    ]) );
  SetListen( ([
    "default" : "The quiet murmur of village life comes from the south.",
    ]) );
  SetSmell( ([
    "default" : "The smells of farm growth come from the west.",
    ]) );
}

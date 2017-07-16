// Coded by Zeratul
// 3-14-2000

#include <lib.h>
#include <domains.h>
#include "../../vacazar.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("The merchant quarters of the Vacazar Town Hall");
  SetLong(
     "This large, stone buidling is an imposing site to see. The "
     "merchant quarters is smaller than the rest of the building, yet "
     "is very decorated. A few beds stand off in the far corner, while "
     "a wooden table stands in the middle. To the north the "
     "foyer of the town hall can be seen. "
  );
  SetItems( ([
     ({"merchant quarters","room"}) : (:GetLong:),
     ({"decorations"}) : "Decorations are scattered about the room. "
     "They seem to brighten up the rather dull room, as the room "
     "is mearly a stone color. ",
     ({"beds","bed"}) : "A few bends stand over in the corner of the room. "
     "The appear to be carved out of stone, with a simple fixture of "
     "moss and some other kinds of cushioning to make them somewhat "
     "comfortable. ",
     "table" : "A wooden table stands in the middle of the room. "
     "A few chairs stand around it, with some clutter on the table "
     "itself. ",
  ]) );
  SetItemAdjectives( ([
     "merchant quarters" : ({"cozy"}),
     "decorations" : ({"colorful","interesting"}),
     "beds" : ({"hard","uncomfortable"}),
     "table" : ({"useful","cluttered"}),
  ]) );
  SetListen( ([
     "default" : "It is rather quiet. ",
  ]) );
  SetSmell( ([
     "default" : "A musty smell hangs in the air. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "north" : V_ROOM + "town_hall/th1",
  ]) );
  }

#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("along Heroes Lane in front of a building");
  SetLong("Heroes Lane continues to the east and west from here. To the west, "
          "the road leads to the Gwonish swamp, a land of ancient evil. To the "
          "east, the road leads back to the heart of the Shire. Sitting unassumingly "
          "along the northern side of the road is a small stone building. The "
          "rolling hills of the Shire spread out in many directions from here.");  
  SetExits( ([
     "east" : LLORYK + "room/hb3",
     "west" : LLORYK + "room/hb1",
     ]) );
  SetItems( ([
    ({ "building", "hall" }) : "This small building serves as the center of "
                               "magical learning in the Shire.",
    ({ "hill", "hills" }) : "The hills of the Shire make for good farmland.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "small", "stone" }),
    "hill"     : ({ "rolling" }),
    ]) );   
  SetEnters( ([
    "building" : LLORYK "room/magic_hall",
    ]) );
  SetListen( ([
     "default" : "Quiet chanting and discussion comes from the building.",
     ]) );
  SetSmell( ([
     "default" : "When the wind blows, the smells of farmland taint the air.",
     ]) );
}

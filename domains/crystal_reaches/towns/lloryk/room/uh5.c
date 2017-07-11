#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the northern road through the Shire");
  SetLong("The northern road passes through the Shire here. Lying on the "
          "eastern side of the road is a small building that serves as the "
          "village meeting place for the Shire. Off to the south the road "
          "curves west directly in front of the Eclat Temple. The rolling "
          "hills of the Shire calmly spread out to the west.");
  SetItems( ([ 
    ({ "hill", "hills" }) : "The hills of the Shire make excellent farmland.",
    ({ "place", "hall", "building" }) :
                        "Open shuttered windows with smooth glass panes "
                        "stare out from the side of this building.  A "
                        "friendly looking door provides entrance to the "
                        "burrow that is marked as the village hall.",
    ]) );
  SetInventory( ([ 
     LLORYK + "obj/fountain" : 1,
      ]) );
  SetExits( ([
     "north" : LLORYK + "room/uh4",
     "south" : LLORYK + "room/uh6",
     "west"  : LLORYK + "room/farm1",
      ]) );
  SetEnters( ([
    "hall" : LLORYK + "room/town_hall",
    ]) );
  SetListen( ([
    "default" : "The occasional discussion from the meeting hall "
                "can be heard",
    ]) );
  SetSmell( ([
    "default" : "The smells of farming waft from the west.",
    ]) );
}

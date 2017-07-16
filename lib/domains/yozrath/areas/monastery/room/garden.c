// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("a beautiful garden");
  SetLong(
    "This stone-paved garden is filled with a variety of plant life. There "
    "are some flower beds around the walls. The fountain in the center is "
    "surrounded by flourishing grape vines. A vegetable patch lies in one "
    "of the corners, likely used to grow food for the monks. A small stream "
    "provides water to the plants and fountain. Stone archways to the east "
    "and west provide access to the rest of the monastery, along with a door "
    "to the south. "
  );
  SetItems( ([
  ({ "garden" }) : (: GetLong :),
  ({ "flowers", "beds" }) :
    "Various flowers grow happily in the beds.",
  ({ "plant", "plants", "life" }) :
    "There are some flower beds, grape vines and a vegetable patch here. ",
  ({ "walls", "wall" }) :
    "The garden is surrounded by a short stone wall, for monks to "
    "sit on and contemplate monkish things.",
  ({ "patch", "vegetables" }) :
    "The vegetable patch serves as a place to grow food for the monks. "
    "There are tomatoes and multiple varieties of beans growing here.",
  ({ "tomatoes", "beans" }) :
    "The vegetables don't quite look ready to be harvested.",
  ({ "vines" }) :
    "These grape vines, while pretty, are probably used to grow grapes "
    "for making wine.",
  ({ "stream", "water" }) :
    "The stream has been directed here from the river, providing water "
    "for all the plant life.",
  ({ "archways", "archway" }) :
    "There are stone archways to the east and west, leading to other "
    "parts of the monastery.",
  ({ "fountain" }) : "Water shoots into the air from this lovely marble "
    "fountain. It looks very refreshing.",
  ]) );
  SetItemAdjectives( ([
    "walls" : ({ "short", "stone" }),
    "vines" : ({ "grape", "flourishing" }),
    "stream" : ({ "small" }),
    "fountain" : ({ "marble", "lovely" }),
    "garden" : ({ "stone-paved", "stone", "paved" }),
    "flowers" : ({ "various", "flower" }),
    "patch" : ({ "vegetable" }),
    "archways" : ({ "stone" }),
    "beds" : ({ "flower" }),
    "plant" : ({ "life" }),
  ]) );
  SetInventory( ([
    AREA_NPC "monk" : 1,
  ]) );
  SetListen( ([
    "default" : "The sound of trickling water originates from the stream.",
  ]) );
  SetSmell( ([
    "default" : "The smell of plant life is a welcome change from the heat "
    "of the desert.",
    "flowers" : "The flowers smell lovely!",
  ]) );
  SetExits( ([
    "west" : AREA_ROOM "dormitory",
    "east" : AREA_ROOM "kitchen",
    "south" : AREA_ROOM "main_hall",
  ]) );
  SetDoor("south", AREA_OBJ + "stained_door");
}

/** Approved by Laoise at Sun May 21 17:02:59 2006. **/
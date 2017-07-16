#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(30);
    SetClimate("underground");
    SetShort("a cave entrance");
    SetLong("The entrance makes a quarter spiral down into a cave.  From "
            "here it heads in four directions, with muddy footprints "
            "accompanying them.  There is green moss growing on the walls "
            "and away from the main paths out of the room.  The cave is "
            "composed of a grey sedimentary rock, damp in many places, "
            "wet in others.");
    SetItems( ([
      ({"entrance", "quarter spiral", "spiral"}) :
        "The cave entrance is fairly small, three feet by four, and makes "
        "a quarter spiral down about twenty feet to the cave floor.",
      ({"four directions", "directions", "direction"}) :
        "The cave heads off north, east, south, and west.",
      ({"muddy footprints", "footprints", "footprint",
        "small footprints", "small footprint"}) :
        "These footprints head off in four direction, more to the south "
        "and east than north or west.",
      ({"green moss", "moss"}) :
        "This is the standard green moss that grows in low light "
        "conditions, it is very soft.",
      ({"walls", "wall", "grey wall", "damp wall"}) :
        "These walls are made of a grey sedimentary rock, they are "
        "damp and many have moss growing on them.",
      ({"path", "paths", "floor"}) :
        "The center part of the cave floor is worn smooth by, "
        "many footsteps.",
      ({"cave", "room"}) :
        "The entire cave is composed of a grey sedimentary rock.",
      ({"rock", "grey sedimentary rock", "wet", "damp", "wet rock",
        "grey rock", "sedimentary rock"}) :
        "The rock in this cave is mostly damp on the walls, "
        "with the occasional wet puddle on the floor.",
        "puddle" :
          "There is a puddle of water on the floor.",
          ]) );
    SetListen( ([
      "default" :
        "There are voices speaking gobyshkin coming from the east and south, "
        "and the frequent drip of water can be heard.",
           ]) );
    SetSmell( ([
      "default" :
        "There is a foul, rancid odor coming from the west."
            ]) );
    SetExits( ([
      "north" : CAVES_ROOM + "caven",
      "east"  : CAVES_ROOM + "caveea",
      "south" : CAVES_ROOM + "caves",
      "west"  : CAVES_ROOM + "cavew",
      "up"    : CAVES_ROOM + "roomce",
            ]) );
    SetInventory( ([
      CAVES_NPC + "bat" : 3,
                ]) );
}

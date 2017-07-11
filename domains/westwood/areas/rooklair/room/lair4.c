#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
 
static void create() {
  room::create();
  
  SetShort("a bat cave");
  SetLong("This room is covered in white and brown stuff.  It appears "
    "to be bat guano.  Small stalagmites hang down from the ceiling "
    "and appears to be a bat roost.  A tunnel leads off to the west "
    "while an opening leads up into the ceiling of the cave.  A "
    "path leads along the wall of the cave and ascends up into the "
    "opening.");
  SetItems( ([
    ({"room","cave"}) : (:GetLong:),
    ({"stuff","guano"}) : "The bat guano is many shades of white and "
      "brown.  It covers everything in the cave making it slimy and "
      "slippery.",
    ({"stalagmites","stalagmite","stalagtites"}) : "These small "
      "cave formations hang down from the ceiling in small points "
      "that look almost dangerous.",
    ({"ceiling","roost"}) : "The ceiling appears to be a perfect "
      "place for bats to roost.  It is covered in stalagmites.",
    ({"opening"}) : "The opening above appears to just be more cave.",
    ({"path"}) : "The path leads along the edge of the wall and "
      "follows up an almost hidden set of stairs.",
  ]) );
  SetItemAdjectives( ([
    "stuff" : ({"white","brown"}),
    "guano" : ({"bat"}),
    "stalagmite" : ({"small"}),
    "roost" : ({"bat"}),
  ]) );
  SetExits( ([
    "up" : R_ROOM + "lair3",
    "west" : R_ROOM + "lair5",
  ]) );
  SetInventory( ([
    R_NPC + "bat" : 10,
  ]) );
  SetAmbientLight(0);
  SetClimate("indoors");
  SetSmell( ([
    "default" : "This room smells of bat guano.",
  ]) );
  SetListen( ([
    "default" : "The flapping of wings and little squeaks fill the room.",
  ]) );
}

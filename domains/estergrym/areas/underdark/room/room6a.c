#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetShort("mouth of a cave");
  SetLong("The mouth of the cave. Large stalactites hang from the ceiling "
          "like fangs. An evil feeling darkness seems to flow up out of the "
          "depths. The light from the opening shows a small tunnel leading "
          "away down to the north. Looking out of the cave the sky can be "
          "seen, somehow it seems dimmer than it ought to.");
  SetExits( ([
          "north" : U_ROOM + "room8a",
          "south" : U_ROOM + "room3a"]) );
  SetItems( ([
          ({ "cave", "mouth", "opening" }) : "The entrance to the cave, large "
          "stalactites hang down like fangs, some reaching almost all the "
          "way to the floor.",
          ({ "stalactite", "stalactites" }) : "A number of stalactites, common "
          "in most caves, hang down from the ceiling.",
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the entrance of the cave "
          "down. In the extreeme darkness, nothing can be seen down the "
          "tunnel.",
          "sky" : "Somehow, if it is possible, the sky seems dimmer, even "
          "though, seen from inside the cave, it should seem brighter.",
          "ceiling" : "A curved, cracked, bumpy rock ceiling with stalactites "
          "hanging off of it.",
          "depths" : "Looking deeper into the cave nothing can be seen in "
          "the darkness but the begining of the tunnel going down to the "
          "north."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetListen( ([
          "default" : "Everything is oddly silent, even the whistling of the "
          "wind seems to have stopped."]) );
  }

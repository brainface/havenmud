#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow tunnel, sloping up to the south and down to the "
          "northeast. An evil darkness seems to flow up out of the depths. "
          "In the extreme darkness, a faint glimmer of light can be seen "
          "up to the south, where the entrance to the cave is. "
          "The tunnel slopes away down into the darkness.");
  SetExits( ([
          "northeast" : U_ROOM + "room10a",
          "south" : U_ROOM + "room6a"]) );
  SetItems( ([
          "entrance" : "A faint glimmer of light can be seen coming from "
          "where the entrance ought to be.",
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the entrance of the cave "
          "down. In the extreeme darkness, nothing can be seen further "
          "down the tunnel.",
          "depths" : "Looking farther down the tunnel nothing can be seen. ",
          "light" : "A faint glimmer of light comming from where the cave "
          "entrance ought to be."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetListen( ([
          "default" : "Everything is completely silent."]) );
  }

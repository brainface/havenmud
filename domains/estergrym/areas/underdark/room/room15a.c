#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow tunnel, it curves around, sloping up to the southwest "
          "and down to the north. A small stream flows through going from "
          "the southwest to the north. An evil darkness seems to flow up "
          "out of the depths. The tunnel seems to open up down to the "
          "southwest.");
  SetExits( ([
          "north" : U_ROOM + "room16a",
          "southwest" : U_ROOM + "room14a"]) );
  SetItems( ([
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the large chamber "
          "down. In the extreme darkness, nothing can be seen further "
          "down the tunnel.",
          "depths" : "In the darkness nothing can be seen further down "
          "the tunnel in either direction.",
          ({ "stream", "small stream", "stream of water" }) : "A small stream "
          "of water, barely more than a trickle. It flows through the tunnel "
          "from the southewest curving around to the north."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }

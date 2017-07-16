#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow tunnel, it curves around, sloping down to the "
          "northeast and up to the southwest. An evil darkness seems to "
          "flow up out of the depths. The tunnel seems to open up down to "
          "the northeast and up to the southwest.");
  SetExits( ([
          "northeast" : U_ROOM + "room14a",
          "southwest" : U_ROOM + "room11a"]) );
  SetItems( ([
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the large chamber "
          "down. In the extreme darkness, nothing can be seen further "
          "down the tunnel.",
          "depths" : "The tunnel seems to open up down to the  northeast "
          "and up to the southwest."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }

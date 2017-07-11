#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow tunnel, it curves around, sloping up to the southwest "
          "and down to the northwest. An evil darkness seems to flow up "
          "out of the depths. In the extreme darkness, even the light from the "
          "entrance, not that far off, is lost. The tunnel slopes away down "
          "into the darkness.");
  SetExits( ([
          "northwest" : U_ROOM + "room12a",
          "southwest" : U_ROOM + "room8a"]) );
  SetItems( ([
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the entrance of the cave "
          "down. In the extreeme darkness, nothing can be seen further "
          "down the tunnel.",
          "depths" : "Nothing can be seen further down the tunnel."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetListen( ([
          "default" : "Everything is completely silent."]) );
  }

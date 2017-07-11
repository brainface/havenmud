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
          "out of the depths. The tunnel seems to open up down to the "
          "northwest.");
  SetExits( ([
          "northwest" : U_ROOM + "room14a",
          "southeast" : U_ROOM + "room10a"]) );
  SetItems( ([
          "darkness" : "Eveything seems oddly dark, even for inside a cave. "
          "Somehow, the darkness is almost touchable.",
          "tunnel" : "A small tunnel leading from the entrance of the cave "
          "down. In the extreme darkness, nothing can be seen further "
          "down the tunnel.",
          "depths" : "The tunnel opens up further down to the  northwest."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetInventory( ([
          U_NPC + "distraught_dwarf" : 1 ]) );
  }

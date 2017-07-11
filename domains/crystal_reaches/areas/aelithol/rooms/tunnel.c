#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(10);
    SetShort("in a tunnel");
    SetDomain("Crystal Reaches");
    SetLong(
      "The walls of the tunnel are very smooth "
      "and are made of a dark, cold stone which is native "
      "to this particular area. Any light shines faintly on "
      "the walls and reveals their flawless design. Deep in "
      "the tunnel, several smaller fragments of the stone "
      "door lie haphazardly along the stone floor, but in "
      "much less concentration. The force which destroyed "
      "the door must have been a massive crushing pressure "
    );
    SetItems( ([
      "tunnel"  :  (: GetLong :),
      ({"floor", "base"})  :
      "The floor is perfectly flat and proceeds directly forward"
      "into the darkness of the tunnel.  It is made of the same "
      "native dark stone as the rest of the tunnel.",
      "stone"  :
      "The stone of the tunnel is very dark.",
      "door"  :
      "The remains of the door to the south have been thrown far into "
      "the tunnel.",
      ({"fragment", "fragments"})  :
      "Pieces of the door which once concealed the tunnel are spread "
      "through the tunnel.  Many of them still have flat surfaces "
      "and were once part of a smooth stone door.",
      ({"wall", "walls", "side", "sides"})  :
      "The walls are made of a dark stone which is very cold.  They "
      "are totally smooth and reflect any light they are exposed to.",
      "dust"  :
      "Thick layers of dust rest on the floor and upon the many "
      "pieces of the shattered door.  The dust forms a thick earthy "
      "cloud with the slightest disturbance.",
    ]) );
    SetItemAdjectives( ([
      "tunnel"    :  ({"perfect", "flat", "direct"}),
      "floor"  :  ({"perfect", "flat", "direct"}),
      "fragment"    :  ({"scattered", "jagged"}),
      "stone"  :  ({"dark", "cold", "hillside"}),
      "door"  :  ({"broken", "shattered"}),
      "wall"    :  ({"perfect", "flawless"}),
      "dust"    :  ({"thick", "layered"}),
    ]) );
    SetSmell( ([
      "default"  :  "Dust and earth fill the air.",
    ]) );
    SetListen( ([
      "default"  :  "Every sound reverberates through the tunnel.", 
    ]) );
    SetExits( ([
      "south"  :  ROOMS + "/tunbeg.c",
      "north"  :  ROOMS + "/oppos.c",
    ]) );
}

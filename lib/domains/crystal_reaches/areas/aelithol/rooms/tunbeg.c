#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(10);
    SetShort("the start of a tunnel");
    SetDomain("Crystal Reaches");
    SetLong(
      "The tunnel in the hillside is perfectly constructed "
      "and obviously of dwarven make. The floor is perfectly " 
      "flat and proceeds directly ahead into the darkness of "
      "the hillside. Large fragments of stone cover the floor "
      "of the tunnel and are wildly scattered all along the "
      "floor. It would seem that a great force has shattered "
      "a once thick stone door. Dust from the destroyed door "
      "still covers the surfaces of the tunnel."
    );
    SetItems( ([
      "tunnel"  :  (: GetLong :),
      ({"floor", "base"})  :
      "The floor is perfectly flat and proceeds directly forward"
      " into the darkness of the tunnel.  It is made of the same "
      "same native dark stone as the rest of the tunnel.",
      ({"portal", "door"})  :
      "Through the portal's dark edges a clearing filled with brown "
      "grass can be seen.  The jagged edges of the portal "
      "hint at the door which once existed there and its violent end.",
      "stone"  :
      "The stone of the tunnel is very dark.",
      ({"grass", "grasses"})  :
      "Grasses can be seen outside the tunnel waving in the breeze.",
      ({"fragment","fragments"})  :
      "Pieces of the door which once concealed the tunnel are spread "
      "through the tunnel.  Many of them still have flat surfaces "
      "and were once part of a smooth, stone door.",
      "door"  :
      "At one time the portal was blocked by a stone door, but now the "
      "scattered fragments are all that remain.",
      ({"wall", "walls", "side", "sides"})  :
      "The sides of the tunnel are rounded with a flat base.  They are "
      "flawlessly constructed from the dark stone of the hillside.",
      "clearing"  :
      "A clearing with brown grasses waving can be seen through the "
      "broken portal.",
      "dust"  :
      "Thick layers of dust rest on the floor and upon the many "
      "pieces of the shattered door.  The dust forms a thick earthy "
      "cloud with the slightest disturbance.",
    ]) );
    SetItemAdjectives( ([
      "tunnel"    :  ({"perfect", "flat", "direct"}),
      "floor"  :  ({"perfect", "flat", "direct"}),
      "grass"  :  ({"waving", "brown", "tall"}),
      "stone"  :  ({"dark", "cold"}),
      "door"  :  ({"shattered", "broken"}),
      "base"    :  ({"perfect", "flat", "direct"}),
      "portal"    :  ({"dark", "broken", "shattered", "hillside"}),
      "fragments"    :  ({"scattered", "jagged"}),
      "wall"    :  ({"perfect", "flawless"}),
      "clearing"    :  "small",
      "dust"    :  ({"thick", "layered"}),
    ]) );
    SetSmell( ([
      "default"  :  "The smell of a fine dust is in the air.",
    ]) );
    SetListen( ([
      "default"  :  "Water is dripping somewhere in the distance.",
    ]) );
    SetExits( ([
      "out"  :  ROOMS + "/clearing.c",
      "north"  :  ROOMS + "/tunnel.c",
    ]) );
}

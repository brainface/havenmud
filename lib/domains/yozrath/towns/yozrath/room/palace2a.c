#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Sheik's Private Salon");
  SetLong(
    "Though small, this private salon is quite richly furnished. Low "
    "wooden seating lines the wall and is covered in various rolled pillows. "
    "The tiling is arranged in a mosaic of sand and palm trees. A small "
    "staircase leads back down to the main palace room."
    );
  SetSmell("The room smells of a musky incense.");
  SetListen("The splashing of the fountain carries up from the courtyard.");
  SetItems( ([
    ({ "room", "space", "salon" }) : (:GetLong:),
    ({ "tile", "tiling", "mosaic" }) : 
       "Intricate tilework covers the wall and floors. Along the wall it is "
       "arranged in a mosaic depicting the beauties of Yozrath: sand and "
       "palms.",
    ({ "wall", "walls" }) : 
       "The walls are tiled and have been cleaned and polished to a high "
       "shine. Along the wall it is arranged in a mosaic depicting the "
       "beauties of Yozrath: sand and palms.",
    ({ "floor", "ground" }) :
       "The floors are tiled and have been cleaned and polished to a high "
       "shine.",
    ({ "courtyard" }) :
       "The courtyard can be seen from the window.",
    ({ "stair", "stairs", "staircase", "case" }) :
       "This small staircase is covered in tile and leads downward.",
    ({ "pillow", "pillows" }) :
       "Small rolled pillows cover the seating, making the wood more "
       "inviting. The silk coverings are a myriad of colors."
    ]) );
  SetItemAdjectives( ([
    "room" : ({ "furnished", "private" }),
    "tile" : ({ "intricate", }),
    "wall" : ({ "clean", "cleaned", "polished", "tiled" }),
    "floor" : ({ "clean", "cleaned", "polished", "tiled" }),
    "arch" : ({ "large", "open" }),
    "seating" : ({ "low", "woden", "covered", }),
    "pillows" : ({ "small", "silk", "rolled" }),
    "staircase" : ({ "small" }),
    ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "down" : YOZRATH_ROOM "palace2",
    ]) );
    
}

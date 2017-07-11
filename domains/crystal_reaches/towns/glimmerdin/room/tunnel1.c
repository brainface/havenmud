#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(15);
  SetShort("a well hewn tunnel");
  SetLong(
    "The tunnel continues to the east and west from here. To the east, the "
    "tunnel seems to curve north and get wider, while to the west the tunnel "
    "seems less important, leading back to the surface. Intricate carvings "
    "on the walls of the tunnel depict the glory of the dwarven race. "
    "To the west lies the checkpoint guarding the entrance and exit from "
    "the city of Glimmerdin. Small balls of light give off just enough of "
    "a glow for dwarven eyes."
    );
  SetSmell( ([
    "default" : "The tunnel has a pleasant earthy smell.",
    ]) );
  SetListen( ([
    "default" : "Deep in the tunnel to the east, faint sounds can be heard.",
    ]) );
  SetProperty("no teleport",1);
  SetItems( ([
    ({ "ball", "light", "balls" }) :
      "Soft white light reflects off the tunnel walls from the magical "
      "balls of light mounted high on the walls.",
    ({ "carving", "carvings" }) :
      "Stories of valour and honor are told by the carvings all along the "
      "tunnel's walls.",
    ({ "walls", "wall" })  :
  	  "Intricate carvings turn an otherwise unimpressive grey stone wall "
  	  "into a masterpiece of art.",
  	({ "stone" }) :
  	  "Flat grey, the stone of the tunnel gives a feeling of impervious "
  	  "strength.  It is difficult to imagine what tools could have cut this "
  	  "tunnel, much less perform the intricate carvings in its surface.",
  	({ "curve", "east" }) :
  	  "The light appears to dim around the northern curve to the east.",
  	({ "checkpoint", "west" }) :
      "The checkpoint is a guardpost to prevent undesirables from entering "
      "Glimmerdin.",
    ]) );
  SetItemAdjectives( ([
    "ball"    : ({ "glowing", "small", "balls", "ball", "of" }),
    "carving" : ({ "intricate" }),
    "wall"    : ({ "tunnel", "tunnel's", "grey", "stone", }),
    "stone"   : ({ "grey" }),
    ]) );
  SetExits( ([
    "east" : G_ROOM  "tunnel2",
    "west" : G_ROOM  "holding",
    ]) );
}

#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(15);
  SetShort("a bend in the tunnel");
  SetLong(
    "The tunnel bends here, opening to the north into the wide expanse of "
    "the central part of the dwarven city. Off to the west, the tunnel, "
    "while wide, has a definite narrowing as it leads back towards the "
    "surface. Set in the walls are small, glowing balls of purest light "
    "which illuminate the tunnel brightly enough for dwarven eyes. Intricate "
    "carvings line the walls, displaying the glory of the dwarven people "
    "through the ages of Kailie's history. A small niche in the wall holds "
    "a cracked wooden door marked as some kind of tavern."
    );
  SetSmell( ([
    "default" : "The tunnel has a pleasant, earthy smell.",
    ]) );
  SetListen( ([
    "default" : "The sounds of city life echo from the north.",
    ]) );
  SetProperty("no teleport",1);
  SetItems( ([
    ({ "ball", "balls" }) :
      "The balls are magical in nature, provided for the tunnel by the "
      "Paladins of Kylin.",
    ({ "carving", "carvings" }) :
      "Stories of valour and honor are told by the carvings all along the "
      "tunnel's walls.",
    ({ "walls", "wall" })  :
  	  "Intricate carvings turn an otherwise unimpressive grey stone wall "
  	  "into a masterpiece of art. A niche in the wall has a cracked door "
  	  "leading to a small tavern.",
  	({ "stone" }) :
  	  "Flat grey, the stone of the tunnel gives a feeling of impervious "
  	  "strength.  It is difficult to imagine what tools could have cut this "
  	  "tunnel, much less perform the intricate carvings in its surface.",
  	({ "tavern", "door", "niche" }) :
  	  "The niche is a rough entrance to a small and dirty tavern.",
    ]) );
  SetItemAdjectives( ([
    "ball"    : ({ "glowing" }),
    "carving" : ({ "intricate" }),
    "wall"    : ({ "tunnel", "tunnel's", "grey", "stone", }),
    "stone"   : ({ "grey" }),
    "tavern"  : ({ "small", "cracked", "wooden", }),
    ]) );
  SetEnters( ([
    "tavern" : G_ROOM "tavern",
    ]) );
  SetExits( ([
    "north" : G_ROOM "gh_south",
    "west"  : G_ROOM "tunnel1"
    ]) );
}

#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Palace Courtyard");
  SetLong(
     "The inside of the palace of the Sheik of Yozrath is everything that "
     "one would expect of such a grandoise structure. Intricate tiling covers "
     "the floor and walls and the ceiling is vaulted, giving a glimpse of "
     "the Sheik's private salon through a second-story window. A tiled "
     "fountain is the focal point of the courtyard. Large, open archways "
     "lead to the west and south and there is an entrance to the palace "
     "aviary to the north."
     );
  SetSmell("The delicious scent of palm dates comes from outside.");
  SetListen("The occasional splash can be heard from the fountain.");
  SetItems( ([
    ({ "courtyard", "structure" }) : (:GetLong:),
    ({ "tile", "tiling" }) : 
       "Intricate tilework covers the wall, floors and fountain, colored "
       "in bright blues, yellows and greens giving the courtyard a cheerful "
       "look.",
    ({ "wall", "walls" }) : 
       "The walls are tiled and have been cleaned and polished to a high "
       "shine. A window overhead opens into the courtyard from the Sheik's "
       "private salon.",
    ({ "window", "shutters", "shutter" }) :
       "The window is large and shutters open from the Sheik's private salon "
       "onto the courtyard, one can get a glimpse of the opulent decorations.",
    ({ "floor", "ground" }) :
       "The floors are tiled and have been cleaned and polished to a high "
       "shine.",
    ({ "fountain" }) :
       "The tiled fountain sits as the main attraction of the palace "
       "courtyard.",
    ({ "arch", "archway", "archways" }) :
       "Large open archways lead off to various parts of the palace.",
    ({ "ceiling" }) :
       "The ceiling is vaulted, reaching towards the sky.",
    ({ "aviary" }) :
       "The palace aviary can be entered from the courtyard. It boasts some "
       "of the most unique birds of the desert.",
    ]) );
  SetItemAdjectives( ([
    "tile" : ({ "intricate", "colored", "bright-blue", "yellow", "green" }),
    "wall" : ({ "clean", "cleaned", "polished", "tiled" }),
    "window" : ({ "large", "open", "second-story" }),
    "floor" : ({ "clean", "cleaned", "polished", "tiled" }),
    "fountain" : ({ "tiled" }),
    "arch" : ({ "large", "open" }),
    "ceiling" : ({ "vaulted" }),
    ]) );
  SetInventory( ([
    YOZRATH_NPC + "guard" : 4,
    ]) );                               
  SetEnters( ([
    "aviary" : YOZRATH_ROOM "aviary",
    ]) );
  SetExits( ([
    "out" : YOZRATH_ROOM "oasis4",
    "west" : YOZRATH_ROOM "palace2",
    "south" : YOZRATH_ROOM "palace3",
    ]) );
    
}

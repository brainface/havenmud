#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Palace Aviary");
  SetLong(
    "This is the palace aviary, a home for many different species of "
    "birds that the Sheik has collected. The walls and floors are covered "
    "in the same intricate tilework that can be found throughout the rest "
    "of the palace. A small fountain sits in the middle of the room and many "
    "potted trees and flowers provide plenty of shelter. Large open windows "
    "cover the walls and are lined with meshing to keep the birds inside. "
    "The courtyard is back out to the south."
    );
  SetSmell("The potted flowers fill the air with a pleasant fragrance");
  SetListen("The birds chirp and sing gaily.");
  SetItems( ([
    ({ "aviary" }) : (:GetLong:),
    ({ "tile", "tiling", "tilework" }) : 
       "Intricate tilework covers the walls and floors, colored in bright "
       "in bright blues, yellows and greens giving the aviary a cheerful "
       "look.",
    ({ "wall", "walls" }) : 
       "The walls are tiled and have been cleaned and polished to a high "
       "shine. Windows covered with mesh look out and let in a gentle "
       "breeze.",
    ({ "window", "windows", "mesh" }) :
       "The windows are large and let in a gentle breeze. A mesh covers them "
       "to keep the birds from escaping.",
    ({ "floor", "ground" }) :
       "The floors are tiled and have been cleaned and polished to a high "
       "shine.",
    ({ "fountain" }) :
       "The small stone fountain sits as in the middle of the room, making "
       "a nice water hole for the birds.",
    ({ "tree", "trees", "flower", "flowers", "foliage" }) :
       "Large potted palm trees and other various foliage fill the room "
       "giving off lovely earthen scents as well as providing shelter for "
       "the birds.",
    ]) );
  SetItemAdjectives( ([
    "tile" : ({ "intricate", "colored", "bright-blue", "yellow", "green" }),
    "wall" : ({ "clean", "cleaned", "polished", "tiled" }),
    "window" : ({ "large", "open", "lined" }),
    "floor" : ({ "clean", "cleaned", "polished", "tiled" }),
    "fountain" : ({ "small", "stone" }),
    "tree" : ({ "potted", "large" }),
    ]) );
  SetInventory( ([
    YOZRATH_NPC "av_bustard" : (random(2)+1),
    YOZRATH_NPC "av_roller" : (random(2)+1),
    YOZRATH_NPC "av_waxbill" : (random(2)+1),
    ]) );
  SetExits( ([
//    "north" : YOZRATH_ROOM "menagerie1",
    "out" : YOZRATH_ROOM "palace",
    ]) );
    
}

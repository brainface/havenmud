//
// At the crossing of a corridor and underground stream
// By Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a damp corridor");
  SetLong(
   "The corridor dips here slightly as the path of an underground stream"
   " crosses it, bringing with it a torrent of icy cold water."
   " The water has knocked through one wall, before running down the"
   " corridor until it reaches another weak point in the opposite wall"
   " and continues on its way. The black and white tiles sparkle prettily"
   " in the water, and the walls of the corridor are the dark grey colour"
   " of damp rock.");
  SetItems( ([
   ({"wall","walls"}) : "The walls are damp from the stream, and"
     " there is a small pair of holes for the stream's entrance and"
     " egress.",
   "corridor" : "The corridor extends to the east and west.",
   "tiles" : "The tiles have mostly fallen into the water, but a few still"
     " tenaciously cling to the ceiling.",
   ({"ceiling","stone"}) : 
     "The ceiling is untouched by the stream, and looks"
     " down with equanamity upon the rushing water below. There are a"
     " few tiles clinging on, but the ceiling is otherwise bare stone.",
   "water" : 
     "The water looks cold and clear. Small tiles sparkle at the bottom.",
   ({"stream","path"}) :
     "The underground stream flows from north to south, entering and"
     " exiting through a pair of small holes.",
   ({"point","hole","holes","entrance","egress"}) :
     "The holes are a matching pair, of similar size and shape. They are"
     " both rounded and smoothed by the passage of the water, but, alas,"
     " are far too small to try to enter.",
    ]) );
  SetItemAdjectives( ([
    "wall" : ({"dark","grey","damp","rock"}),
    "corridor" : "damp",
    "tiles" : ({"black","white","sparkling","pretty","tenacious"}),
    "ceiling" : ({"untouched","bare","stone"}),
    "water" : ({"icy","cold","rushing","clear"}),
    "stream" : "underground",
    "hole" : ({"entrance","egress","of","weak","small","pair",
               "rounded","smoothed"}),
    ]) );
  SetListen( ([
    "default" : "The gurgle of flowing water comes from the stream.",
    ({"stream"}) : "The water gurgles as it flows past.", 
   ]) );
  SetSmell( ([
    "default" : "The air is filled with the smell of crisp mountain"
       " streamwater.",
    "stream" : "The water smells clean.",
    ]) );
  SetClimate("underground");
  SetAmbientLight(5);
  SetInventory( ([
    RNQ_NPC + "rat.c" : 1,
    ]) );
  SetExits( ([
    "east" : RNQ_RM + "wcor1.c",
    "west" : RNQ_RM + "tower1.c",
    ]) );
}

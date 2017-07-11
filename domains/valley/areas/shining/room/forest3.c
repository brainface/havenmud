/* Shinning Forest Room 3 Intersection
 * Created by Ohtar
*/
#include <lib.h>
#include "../sf.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a paved intersection in the forest");
  SetLong(
    "The paved path comes to a intersection here. Every stone seems to be "
    "lined up perfectly with the next forming a diamond. Several bushes "
    "form around the path. Oddly, not one seems to be out of place. The "
    "trees here appear to be much small then the others. There is a "
    "small ford over the stream here heading south. One can also travel "
    "either north or east which both continue into the forest. Heading "
    "west leads back towards the entrance. " );

SetItems( ([
     ({"Intersection"}) :
                  "The intersection is made up for granite stones that form "
                  "a diamond shape here. There are several bushes surrounding "
                  "the stones. ",
     ({"diamond"}) :
                  "The stones line up perfectly with each other to form a "
                  "diamond shape.",
     ({"paved path", "very small path", "very small paved path", "path"}) : 
                  "The very small paved path is made of granite. Every stone "
                  "seems to be lined up perfectly with the next. Along each "
                  "side is a row of bushes.",
     ({"stone", "stones"}) :
                  "The stones appear to be laying along the side of the path "
                  "in a perfect line. They are sandy tan in color and perfectly 
"
                  "oval.",
     ({"ford"}) :
                  "The small ford is made up of layers of thick bark and "
                  "heavy brush.",
     ({"stream"}) :
                  "The stream has a small forge over it that blocks any "
                  "possible access here.",
     ({"beautiful forest", "shining forest", "trees" , "tree", "large trees", 
       "large tree"}) :
                  "All around the trees tall. There limbs are small enough " 
                  "to leave a good view of the sky. They are tan in color "
                  "and appear to be intact. ",
     ({"bushes", "bush", "small bushes"}) :
                  "The small bushes here are very green. They are trimmed "
                  "perfectly in height and shape. They are lined up around "
                  "the diamond shaped stones. ",  ]) );
SetListen( ([ "default" : "The sounds of exotic birds ring in your ears.",   
       ]) );
SetSmell( ([ "default" : "The smell of sweet berries and fruits fill the air.", 
       ]) );

SetInventory( ([
        SF_NPC + "/protector1" : 2,
        SF_NPC + "/defender1" : 2,
  ]) );
SetExits( ([
    "west" : SF_ROOM "forest2",
    "east" : SF_ROOM "forest4",
    "north" : SF_ROOM "forest3N1",
    "south" : SF_ROOM "forest3S1",
  ]) ) ;
}

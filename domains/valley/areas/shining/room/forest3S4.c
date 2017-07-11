/* Shinning Forest Room 3s4
 * Created by Ohtar
 */
#include <lib.h>
#include "../sf.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("an intersection in the forest");
  SetLong(
    "The very small paved path comes to a road heading east here. "
    "The stones on the ground here are slightly out of order. The "
    "trees stand tall in the sky blocking out all sunlight. Oddly, "
    "it seems to be rather bright here. The path continues south "
    "along the edge of the trees. The only other direction of travel "
    "would be back north towards the opening of the shining forest. " );

SetItems( ([
     ({ "paved path", "very small path", "very small paved path" }) : 
                  "The very small paved path is made of granite. The "
                  "stones seem to be slightly out of order. Along each "
                  "side is a row of bushes.",
     ({ "shining forset", "trees" , "tree"}) : 
                  "The trees stand about fifty feet tall. They are brown "
                  "in color with glowing green leaves. ",
     ({ "bushes", "bush", "small bushes" }) : 
                  "The small bushes here are very green. They are trimmed "
                  "perfectly in height and shape. They run along side the "
                  "path. ",
     ({"sky"}) :
                  "The sky is completely blocked out by the trees. "   ]) );


SetListen( ([ "default" : "The sounds of leaves blowing can be heard here.",   
         ]) );
SetSmell( ([ "default" : "The overpowering smell of flowers floats in the air.",
        ]) );
SetInventory  ( ([ SF_NPC + "/protector1" : 3,
  ]) );
SetExits( ([
    "east" : SF_ROOM "forest3S4E1",
    "north" : SF_ROOM "forest3S3",
    "south" : SF_ROOM "forest3S5",  
  ]) ) ;
}

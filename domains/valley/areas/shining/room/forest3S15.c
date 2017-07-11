/* Shinning Forest Room 3S15
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
    "The very small paved path intersects with a road heading "
    "east. It is made up of granite stones decorated with flowers "
    "of all different colors. Every stone seems to be lined up "
    "perfectly with the next. Several bushes run along each side "
    "of the path. Oddly, not one seems to be out of place. The trees "
    "here are much smaller then the others. The only other exit is "
    "back north towards the opening of the shining forest. ");
SetItems( ([
     ({ "paved path", "very small path", "very small paved path", 
        "stones", "stone" }) : 
                  "The very small paved path is made of granite and "
                  "decorated with flowers. Every stone seems to be "
                  "lined up perfectly with the next. Along each side "
                  "is a row of bushes.",
     ({ "beautiful forest", "shining forset", "trees" , "tree", 
        "large trees", "large tree" }) : 
                  "All around the trees stand very tall. There limbs "
                  "sprawl across the sky covering every inch. They are "
                  "brown in color and appear to be very solid. Several "
                  "of the trees have a small hole in them about fifteen "
                  "feet up them. Many of the the leaves on the trees are "
                  "a glowing green.",
     ({ "bushes", "bush", "small bushes" }) : 
                  "The small bushes here are very green. They are trimmed "
                  "perfectly in height and shape. They run right down the "
                  "side of the path. Not one of them seems to be out of "
                  "line.",  ]) );
SetListen( ([ "default" : "The sounds of exotic birds ring in your ears.",   
  ]) );
SetSmell( ([ "default" : "The smell of sweet berries and fruits fill the air.", 
  ]) );
SetInventory  ( ([ SF_NPC + "/protector1" : 2,
  ]) );
SetExits( ([
    "north" : SF_ROOM "forest3S14",
    "east" : SF_ROOM "forest3S15E1"  
  ]) ) ;
}

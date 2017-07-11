/* Shinning Forest Room: forest3S15E10
 * Created by Ohtar
 */
#include <lib.h>
#include "../sf.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a corner in the forest");
  SetLong(
    "The very small paved path here is made up of granite. Every "
    "stone seems to be lined up perfectly with the next. Several "
    "bushes run along each side of the path. Oddly, not one seems "
    "to be out of place. The path does however come to a curve "
    "here heading north. The very large trees here block out any "
    "further travel to the east. The only other direction of travel "
    "is back west." );
SetItems( ([
     ({ "paved path", "very small path", "very small paved path" }) : 
                  "The very small paved path is made of granite. "
                  "Every stone seems to be lined up perfectly with "
                  "the next. Along each side is a row of bushes.",
     ({ "beautiful forest", "shining forset", "trees" , "tree", 
        "large trees", "large tree" }) : 
                  "The trees are solid brown and have beautiful "
                  "green leaves on them. They are very large and "
                  "block out all direction of travel to the east. ", 
     ({ "bushes", "bush", "small bushes" }) : 
                  "The small bushes here are very green. They are "
                  "trimmed perfectly in height and shape. They run right "
                  "down the side of the path. Not one of them seems to "
                  "be out of line. ",
     ({ "leaf", "leaves" }) : 
                  "The leaves on the trees are all glowing green. They "
                  "seem to luminate the path. ",
  ]) );
SetListen( ([ "default" : "The sounds of exotic birds ring in your ears.",   ]) 

);
SetSmell( ([ "default" : "The smell of sweet berries and fruits fill the air.", 

  ]) );
SetInventory  ( ([ SF_NPC + "/protector1" : 3,
                   SF_NPC + "/defender1" : 1,
  ]) );

SetExits( ([
    "west" : SF_ROOM "forest3S15E9",
    "north" : SF_ROOM "forest13S14",
  ]) ) ;
}

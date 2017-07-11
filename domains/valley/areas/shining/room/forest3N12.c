/* Shinning Forest Room 3N12
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
    "The very small paved path comes to a road heading east here. There is a small "
    "sign standing in the corner. It has been nearly engulfed by bushes. In " 
    "corner sits a very large statue. It has been surrounded by beautiful flowers "
    "of all colors as well as several bushes. The trees here are much smaller then "
    "the others and gray in color. The path continues north along the edge of the "
    "trees. The only other direction of travel would be back south towards the "
    "opening of the shining forest. " );

SetItems( ([
     ({ "paved path", "very small path", "very small paved path" }) : 
                  "The very small paved path is made of granite. Every stone seems to "
                  "be lined up perfectly with the next. Along each side is a row of bushes.",
     ({ "beautiful forest", "shining forset", "trees" , "tree"}) : 
                  "The trees are gray in color. They seem to have many holes in however they "
                  "appear to be very healthy. ",
     ({ "bushes", "bush", "small bushes" }) : 
                  "The small bushes here are very green. They are trimmed perfectly in height "
                  "and shape. They run right down the side of the path. Not one of them seems "
                  "to be out of line. ",
     ({ "statue", "large statue", "very large statue" }) : 
                  "The statue seems to resemble that of a sprite. It is very large however it has"
                  "tiny wings. The whole statue is very well designed and colored. ",
     ({ "flower", "beautiful flowers" }) : 
                  "The flowers are many different colors. They are surrounding the base of the "
                  "statue. From the looks of it they are obviously well taken care of.",
     ({ "small sign", "sign" }) : 
                  "The sign is made up of a tree limb. It has a long wooden pole holding it into "
                  "the ground. The pole has many carvings cut into it. The whole pole is covered "
                  "with bushes. One could possibly read the sign. ",
  ]) );


SetListen( ([ "default" : "The sounds of leaves blowing can be heard here.",   ]) 
);
SetSmell( ([ "default" : "The overpowering smell of flowers floats in the air.", 
  ]) );
SetInventory( ([
        SF_NPC + "/protector1" : 3,
  ]) );

SetExits( ([
    "east" : SF_ROOM "forest3N12E1",
    "north" : SF_ROOM "forest3N13",
    "south" : SF_ROOM "forest3N11",  
  ]) ) ;
}

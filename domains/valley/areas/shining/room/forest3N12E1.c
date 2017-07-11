/* Shinning Forest Room 3N12E1
 * Created by Ohtar
 */
#include <lib.h>
#include "../sf.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a paved path in the forest");
  SetLong(
    "The very small paved path comes ends before a massive oak tree. "
    "The tree is covered in vines and has flowers growing from it. "
    "The base of the tree is surrounded by many rocks and bushes. "
    "Next to the tree is a small wooden tower. The rest of the trees "
    "here are much smaller then the Oak. The only exit is back west. "
         );
SetItems( ([
     ({ "paved path", "very small path", "very small paved path" }) : 
                  "The very small paved path is made of granite. Every "
                  "stone seems to be lined up perfectly with the next. "
                  "Along each side is a row of bushes.",
     ({ "beautiful forest", "shining forset", "trees"}) : 
                  "The trees are gray in color. They seem to have many "
                  "holes in however they appear to be very healthy. ",
     ({"oak tree", "oak", "massive tree","tree"}) : 
                  "The tree stands at least seventy-five feet tall. "
                  "There are ten holes in the front of the tree, one "
                  "much larger then the others. There is something carved "
                  "in between the holes that says To disturb this area "
                  "would upset the entire forest. ",
     ({ "bushes", "bush", "small bushes" }) : 
                  "The small bushes here are very green. They are trimmed "
                  "perfectly in height and shape. They run right down the "
                  "side of the path. Not one of them seems to be out of "
                  "line. ",
     ({ "statue", "large statue", "very small statue" }) : 
                  "The statue seems to resemble that of a sprite. It is "
                  "very large however it has tiny wings. The whole statue "
                  "is very well designed and colored. It stands in front "
                  "of a very large oak tree.",
     ({ "flower", "beautiful flowers" }) : 
                  "The flowers are many different colors. They are "
                  "surrounding the base of the statue. From the looks of "
                  "it they are obviously well taken care of.",
  ]) );


SetListen( ([ "default" : "The sounds of leaves blowing can be heard here.",   
         ]) );
SetSmell( ([ "default" : "The overpowering smell of flowers floats in "
                         "the air.",  
        ]) );
SetInventory( ([
        SF_NPC + "/protector1" : 2,
        SF_NPC + "/defender1" : 1,
  ]) );

SetExits( ([
    "west" : SF_ROOM "forest3N12",
   ]) ); 

 SetEnters( ([ 
      "oak" : SF_ROOM + "forest3N12E2oak",     
  ]) ) ;
}

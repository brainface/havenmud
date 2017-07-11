/* Shinning Forest Room 0 
 * Created by Ohtar
 */
#include <lib.h>
#include <domains.h>
#include "../sf.h"
inherit LIB_ROOM;


int PreExit();

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a paved path in the forest");
  SetLong(
    "The very small paved path here is made up of granite. Every "
    "stone seems to be lined up perfectly with the next. Several "
    "bushes run along each side of the path. Oddly, not one seems "
    "to be out of place. The very large trees here appear to be "
    "hundreds of years old. They stand so tall into the sky they "
    "block out even the smallest amount of sunlight. However, "
    "strangely enough it seems to be rather bright here. The path "
    "continues east along the stream further into the forest. The "
    "only other direction of travel would be back south towards "
    "the opening of the shining forest. " );

SetItems( ([
     ({ "paved path", "very small path", "very small paved path" }) : 
                  "The very small paved path is made of granite. Every "
                  "stone seems to be lined up perfectly with the next. "
                  "Along each side is a row of bushes.",
     ({ "beautiful forest", "shining forset", "trees" , "tree", 
        "large trees", "large tree" }) : 
                  "All around the trees stand very tall. There limbs "
                  "sprawl across the sky covering every inch. They are "
                  "brown in color and appear to be very solid. Several "
                  "of the trees have a small hole in them about fifteen "
                  "feet up them. Many of the the leaves on the trees "
                  "are a glowing green.",
     ({ "sky" }) : 
                  "The sky is not visible from here. ",
     ({ "bushes", "bush", "small bushes" }) : 
                  "The small bushes here are very green. They are "
                  "trimmed perfectly in height and shape. They run right "
                  "down the side of the path. Not one of them seems "
                  "to be out of line. ",
     ({ "leaf", "leaves" }) : 
                  "The leaves on the trees are all glowing green. They "
                  "seem to luminate the path. ",  ]) );
SetListen( ([ "default" : "The sounds of exotic birds ring in your "
                          "ears.", ]) );
SetSmell( ([ "default" : "The smell of sweet berries and fruits fill "
                         "the air.", 
]) );

SetInventory( ([
    SF_OBJ + "/stream" : 1,
    SF_NPC + "/protector1" : 1,
    SF_NPC + "/defender" : 1,  ]) );

SetExits( ([ "east" : SF_ROOM "forest1",
        ]) );

AddExit("south", "/domains/valley/virtual/valley/-10,15", (: PreExit :));
}

int PreExit() {
  if (this_player()->id("sforest_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
   }
 return 1;


}

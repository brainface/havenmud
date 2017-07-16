/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: forest02.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: September 10th, 1998
// Abstract: This is the second room on the way to the lair of Naluris.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("near an opening to an underground cave");
  SetDayLong("The overhanging trees of the dark part of the forest open "
             "into this grove. Much of the sky is visible here. A massive "
             "opening in the ground slopes heavily into the earth. Green "
             "grass covers the ground and although the area is tranquil, "
             "the opening in the ground seems ominous.  The area is "
             "filled with sunlight.");
  SetNightLong(
             "The overhanging trees of the dark part of the forest open "
             "into this grove. Much of the sky is visible here. A massive "
             "opening in the ground slopes heavily into the earth. Green "
             "grass covers the ground and although the area is tranquil, "
             "the opening in the ground seems ominous.  The area is "
             "filled with moonlight.");
  SetItems( ([
           ({"trees"}) : "All kinds of trees can be seen all throughout the "
               "forest, but block movement in almost every direction.",
           ({"ground"}) : "The ground is there, just like you'd expect it "
               "to be.",
           ({"forest", "jidoor forest"}) : "The forest is all around you.",
           ({"tree"}) : "No one tree has any significant differences from "
               "any of the others.",
           ({"air"}) : "The air? No one can see that.",
           ({"grass"}) : "The grass here in the grove is lush and very "
               "green.",
           ({"lair","opening","cave"}) : "The huge opening appears to lead "
               "into some caves under the forest."
          ]) );
 SetItemAdjectives( ([
            "forest" : ({ "jidoor" }),
            "air" : ({ "fresh", "clean" }),
            "trees" : ({"massive","larger","smaller","creaking","moaning"})
                  ]) );
  SetListen( ([ 
            "default" : "The sounds of trees creaking and leaves rustling "
               "echo around you.",
            "trees" : "The older trees are moaning as they fight the wind.",
           ]) );
  SetSmell( ([ 
            "default" : "The scent of wildflowers fades here and only the "
               "pleasant smell of the forest fills your sense of smell.",
            "air" : "It smells very fresh."
          ]) );
  SetExits( ([
            "north" : d_room + "/forest01"
          ]) );
  SetEnters( ([
            "lair" : d_room + "/lair01"
           ]) );
  }

/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: forest01.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: September 10th, 1998
// Abstract: This is the first room on the way to the lair of Naluris.
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
  SetShort("a dark part of the Jidoor Forest");
  SetDayLong("The overhanging trees of the forest block much of the "
             "sunlight. Broken branches and leaves litter the ground "
             "everywhere. Massive trees are everywhere and movement in "
             "most directions is not possible.");
  SetNightLong(
             "The overhanging trees of the forest block much of the "
             "moonlight. Broken branches and leaves litter the ground "
             "everywhere. Massive trees are everywhere and movement in "
             "most directions is not possible.");
  SetItems( ([
           ({"trees"}) : "All kinds of trees can be seen all throughout the "
               "forest, but block movement in almost every direction.",
           ({"ground"}) : "The ground is there, just like you'd expect it "
               "to be.",
           ({"forest", "jidoor forest"}) : "The forest is all around you.",
           ({"tree"}) : "No one tree has any significant differences from "
               "any of the others.",
           ({"air"}) : "The air? No one can see that.",
           ({"branches","branch","leaves","leaf"}) : 
                       "Branches and leaves litters the ground.",
           ({"flower", "wildflower"}) : "Of the many wildflower growing "
               "all over the forest, it's difficult to decide which flower "
               "to examine more closely.",
           ({"flowers", "wildflowers"}) : "Wildflowers grow all over the "
               "forest."
          ]) );
 SetItemAdjectives( ([
            "forest" : ({ "jidoor" }),
            "branches" : ({ "broken" }),
            "leaves" : ({ "rustling" }),
            "air" : ({ "fresh", "clean" }),
            "wildflowers" : ({"scent of ", "strong scent of"}),
            "flowers" : ({"scent of ", "strong scent of"}),
            "wildflower" : ({"scent of", "strong scent of"}),
            "flower" : ({"scent of", "strong scent of"}),
            "trees" : ({"massive","larger","smaller","creaking","moaning"})
                  ]) );
  SetListen( ([ 
            "default" : "The sounds of trees creaking and leaves rustling "
               "echo around you.",
            "trees" : "The older trees are moaning as they fight the wind.",
            "leaves" : "The sounds of the leaves rustling grows quite loud "
               "at times."
           ]) );
  SetSmell( ([ 
            "default" : "The clean air of the forest smells fresh and the "
               "scent of wildflowers is strong.",
          ({"wildflowers","flowers"}) : "The wildflowers smell as wonderful "
               "as the scent of a beautiful goddess.",
          ({"wildflower","flower"}) : "The wildflowers smell as wonderful "
               "as the scent of a beautiful goddess.",
            "air" : "It smells very fresh."
          ]) );
  SetExits( ([
            "north" : d_room + "/path07",
            "south" : d_room + "/forest02"
          ]) );
  }

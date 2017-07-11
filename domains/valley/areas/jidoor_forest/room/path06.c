/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: path06.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is the sixth part of the path in Jidoor Forest that leads 
//           towards a bridge where one can fish.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 30th, 1998 - Fixed error in SetDayLong
// Last Update: 
/* ----------------------------------------------------------------------- */


#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a path in Jidoor Forest");
  SetDayLong(
            "This small path runs south and northeast through the forest "
            "southeast of Jidoor. Many trees with branches hanging over the "
            "path block movement in every directions except south and "
            "northeast. The sunlight shines through the trees illuminating "
            "the path quite well and the wildflowers along the sides of the "
            "path seem to be enjoying it. Leaves are strewn about the "
            "forest but the path itself is free of debris or flowers and "
            "looks well kept."
            );
  SetNightLong(
            "This small path runs east and west through the forest "
            "southeast of Jidoor. Trees block movement in almost every "
            "direction except for the route of the path. The moonlight "
            "creates and erie and dim glow to the surroundings as it fights "
            "its way through the branches hanging over the path."
              );
  SetItems( ([ 
          ({"path"}) : "The dirt path running though the forest runs south "
              "and northeast from here.",
          ({"trees"}) : "All kinds of trees can be seen all throughout the "
              "forest, but block movement in almost every direction.",
          ({"ground"}) : "The ground is there, just like you'd expect it to "
              "be.",
          ({"forest", "jidoor forest"}) : "The forest is all around you.",
          ({"tree"}) : "No one tree has any significant differences from "
              "any of the others.",
          ({"branches"}) : "Large branches dim the light from the sky.",
          ({"branch"}) : "Many branches hang over the path but none are of "
              "any more interest then the others.",
          ({"debris"}) : "There is no forest debris lying near or on the "
              "path but it is quite visible throughout the forest.",     
          ({"leaf"}) : "There are many leaves lying in the forest, none any "
              "more interesting than any other.",
          ({"leaves"}) : "The leaves littering the sides of the path are in "
              "a constant state of motion as the wind blows them further "
              "along the path in both directions.",
          ({"air"}) : "The air? No one can see that!",
          ({"flower", "wildflower"}) : "Of the many wildflower growing all "
              "over the forest, it's difficult to decide which flower to "
              "examine more closely.",
          ({"flowers", "wildflowers"}) : "Wildflowers grow all over the "
              "forest."
            ]) );
 SetItemAdjectives( ([ 
            "path" : ({ "small", "dirt" }),
            "forest" : ({ "jidoor" }),
            "branches" : ({ "overhanging", "large" }),
            "leaves" : ({ "rustling" }),
            "air" : ({ "fresh", "clean" }),
            "wildflowers" : ({"scent of ", "strong scent of"}),
            "flowers" : ({"scent of ", "strong scent of"}),
            "wildflower" : ({"scent of", "strong scent of"}),
            "flower" : ({"scent of", "strong scent of"}),
            "trees" : ({"massive","larger","smaller","creaking","moaning" })
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
  SetInventory( ([
             d_npc + "/m_jidoor_bird" : 1,
             d_npc + "/f_jidoor_bird" : 1
              ]) );
  SetExits( ([
             "northeast" : d_room + "/path03",
             "south" : d_room + "/bridge01" ]) );
  }

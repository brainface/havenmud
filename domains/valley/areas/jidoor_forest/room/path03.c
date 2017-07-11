/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: path03.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 17th, 1998
// Abstract: This is the third part of the path of Jidoor forest and it 
//           branches off northeast to the keep and southwest towards a 
//           bridge.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */


#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("a fork of the path in Jidoor Forest");
  SetDayLong(
            "The path branches to northwest, southwest and east of here. "
            "The sunlight shines brightly through the trees creating a calm "
            "and peaceful atmosphere. The rest of the trees in the forest "
            "calmly sway in the wind while the larger ones moan about being "
            "bothered. Branches, leaves, and flowers are strewn about the "
            "forest but the path itself is free of debris or flowers and "
            "looks well kept."
            );
  SetNightLong(
            "This small path branches southwest, northwest and east through "
            "Jidoor Forest. Trees are visible in all directions with " 
            "branches and some debris not far from the path. The moonlight "
            "shines brightly through the trees from overhead."
            );
  SetItems( ([ 
          ({"path"}) : "The dirt path running though the forest runs east "
              "and west from here.",
          ({"trees"}) : "All kinds of trees can be seen all throughout the "
              "forest.",
          ({"ground"}) : "The ground is there, just like you'd expect it to "
              "be.",
          ({"forest", "jidoor forest"}) : "The forest is all around you.",
          ({"tree"}) : "No one tree has any significant differences from "
              "any of the others.",
          ({"branches"}) : "Dead branches lie on the ground in several "
              "areas.",
          ({"branch"}) : "There are many branches lying about but none of "
              "any more interest then the others.",
          ({"debris"}) : "There is no forest debris lying near or on the "
              "path but it is quite visible throughout the forest.",
          ({"leaf"}) : "There are many leaves lying in the forest, none "
              "any more interesting than any other.",
          ({"leaves"}) : "The leaves littering the sides of the path are "
              "in a constant state of motion as the wind blows them "
              "further along the path in both directions.",
          ({"air"}) : "The air? No one can see that",
          ({"flower", "wildflower"}) : "Of the many wildflower growing all "
              "over the forest, it's difficult to decide which flower to "
              "examiNe more closely.",
          ({"flowers", "wildflowers"}) : "Wildflowers grow all over the "
              "forest."
          ]) );
 SetItemAdjectives( ([ 
            "path" : ({ "small", "dirt", "well kept" }),
            "forest" : ({ "jidoor" }),
            "branches" : ({ "dead" }),
            "air" : ({ "fresh", "clean" }),
            "leaves" : ({ "rustling" }),
            "air" : ({ "fresh", "clean" }),
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
           "default" : "The air of the forest smells clean, fresh and "
               "pleasantly like wildflowers.",
         ({"wildflowers","flowers"}) : "The wildflowers smell as wonderful "
               "as the scent of a beautiful goddess.",
         ({"wildflower","flower"}) : "The wildflowers smell as wonderful as "
               "the scent of a beautiful goddess.",
           "air" : "It smells very fresh."
          ]) );
  SetExits( ([
           "east" : d_room + "/path02",
           "northwest" : d_room + "/path04",
           "southwest" : d_room + "/path06"
          ]) );
  }

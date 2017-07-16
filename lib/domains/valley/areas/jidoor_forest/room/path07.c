/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: path07.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is the end of the second part of the path and will 
//           eventually lead to the lair of the Naluris and other possible 
//           expansion areas.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// 	             August 30th, 1998 - Fixed error in Day and Long Desc
//                   November 17th, 1998 - Added exit to Telgaris' area.
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;

#include "../jidoor_forest.h"
#define ranger_exit "/domains/valley/areas/ranger_hall/room/path1"

  static void create()
  {
  room::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("the end of a path running through Jidoor Forest");
  SetDayLong(
             "This small path ends here. The Jidoor Forest "
             "looks somewhat "
             "darker south of this point. Many trees with branches hanging "
             "over the path block movement in every directions except "
             "north. Sunlight shines through the trees "
             "illuminating the "
             "path but nearly as well as the other areas of the forest. "
             "There are wildflowers everywhere, including the path. Leaves "
             "are strewn about the path and it is cluttered with debris.");
  SetNightLong(
             "This small path ends here. The Jidoor Forest "
             "looks somewhat "
             "darker south of this point. Many trees with branches hanging "
             "over the path block movement in every directions except "
             "north. Moonlight shines through the trees "
             "illuminating the "
             "path with a dark glow. Wildflowers are everywhere, including "
             "the path itself and leaves other debris mark the end of the "
             "path.");
  SetItems( ([
          ({"path"}) : "The dirt path heads north here.",
           ({"trees"}) : "All kinds of trees can be seen all throughout the "
               "forest, but block movement in almost every direction.",
           ({"ground"}) : "The ground is there, just like you'd expect it "
               "to be.",
           ({"forest", "jidoor forest"}) : "The forest is all around you.",
           ({"tree"}) : "No one tree has any significant differences from "
               "any of the others.",
           ({"air"}) : "The air? No one can see that.",
           ({"branches"}) : "Large branches dim the light from the sky.",
           ({"branch"}) : "Many branches hang over the path but none are "
               "of any more interest then the others.",
           ({"debris","leaves","leaf"}) : "Debris and leaves are scattered "
               "around the path.",
           ({"flower", "wildflower"}) : "Of the many wildflower growing "
               "all over the forest, it's difficult to decide which flower "
               "to examine more closely.",
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
            "north" : d_room + "/bridge01",
            "east" : ranger_exit,            
          ]) );         
}

string GetObviousExits() {
  if (this_player()->GetGuild() == "ranger") {
     return ::GetObviousExits();
    }
  else {
  return (implode(GetExits() - ({ "east" }), ", ") );
  }
 }

/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: path01.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: This is the first part of the path in the forest
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */


#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"

int PreExit();

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a small path just off of Jidoor Road");
  SetDayLong(
            "This small dirt path begins here, running west from Jidoor "
            "Road deeper into the Jidoor Forest. An expanse of trees block "
            "movement in every direction except west and east. The sunlight "
            "shines through the trees illuminating the path well. "
            "Wildflowers along the sides of the path seem to be enjoying "
            "the sunlight. Leaves are strewn about the forest and along "
            "side the path but the path itself is free of debris or flowers "
            "and looks well kept."
            );
  SetNightLong(
            "This small path runs west from Jidoor road deeper into the "
            "forest. Trees block movement in all directions but west and "
            "east.  The moonlight creates and erie but bright glow to the "
            "path. Wildflowers grow along side the path but the path itself "
            "is clean from debris."
              );
  SetItems( ([ 
          ({"path"}) : "The dirt path running though the forest runs east "
              "and west from here.",
          ({"trees"}) : "All kinds of trees can be seen all throughout the "
              "forest, but block movement in every direction, except for "
              "east and west.",
          ({"ground"}) : "The ground is there, just like you'd expect it "
              "to be.",
          ({"forest", "jidoor forest"}) : "The forest is all around you, "
              "with the exception of to the east where you easily see "
              "Jidoor Road.",
          ({"tree"}) : "No one tree has any significant differences from "
              "any of the others.",
          ({"debris"}) : "There is no forest debris lying near or on the "
              "path but it is quite visible throughout the forest.",
          ({"road"}) : "Jidoor Road is just a little east of here.",
          ({"jidoor"}) : "It is impossible to make out any details of the "
              "city of Jidoor from here.",
          ({"leaves"}) : "The leaves littering the sides of the path are "
              "in a constant state of motion as the wind blows them on to "
              "Jidoor Road and further along the sides of the path.",
          ({"leaf"}) : "There are many leaves lying in the forest, none "
              "any more interesting than any other.",
          ({"air"}) : "The air? No one can see that",
          ({"flower", "wildflower"}) : "Of the many wildflowers growing "
              "all over the forest, it's difficult to decide which flower "
              "to examine more closely.",
          ({"flowers", "wildflowers"}) : "Wildflowers grow all over the "
              "forest."
            ]) );
 SetItemAdjectives( ([
            "path" : ({ "small", "dirt", "well kept" }),
            "road" : ({ "jidoor" }),
            "forest" : ({ "jidoor" }),
            "branches" : ({ "overhanging" }),
            "leaves" : ({ "rustling" }),
            "air" : ({ "fresh", "clean" }),
            "wildflowers" : ({"scent of ", "strong scent of"}),
            "flowers" : ({"scent of ", "strong scent of"}),
            "wildflower" : ({"scent of", "strong scent of"}),
            "flower" : ({"scent of", "strong scent of"}),
            "trees" : ({"massive","larger","smaller","creaking","moaning",
                        "expanse of"})
                  ]) );
  SetListen( ([ 
            "default" : "The sounds of trees creaking and leaves rustling "
              "echo around you.",
            "trees" : "The older trees are moaning as they fight the wind.",
            "leaves" : "The sounds of the leaves rustling grows quite "
              "loud at times."
             ]) );
  SetSmell( ([ 
            "default" : "The scent of wildflowers is prevelant but the air "
              "smells clean and fresh.",
          ({"wildflowers","flowers"}) : "The wildflowers smell as wonderful "
              "as the scent of a beautiful goddess.",
          ({"wildflower","flower"}) : "The wildflowers smell as wonderful "
              "as the scent of a beautiful goddess.",
            "air" : "It smells very fresh."
            ]) );
  SetInventory( ([ 
            d_npc + "/wandering_priest" : 1,
              ]) );
  SetExits( ([
            "west" : d_room + "/path02",
            ]) );
  AddExit("east" , "/domains/valley/virtual/valley/8,8", (: PreExit :) );
}

int PreExit() {
  if (!userp(this_player())) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
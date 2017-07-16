/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: bridge01.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: This is a small bridge in Jidoor Forest where one can 
//                fish.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */
#include <lib.h>
#include "../jidoor_forest.h"

inherit LIB_FISHING;
static void create()
  {
  fishing::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a small bridge over a creek in Jidoor Forest");
  SetDayLong(
             "A small, wooden bridge crosses overtop of a creek here in "
             "Jidoor Forest. The forest is filled with trees that tend "
             "to block travel in more directions then not, but it would "
             "be easy to travel north and south from here along the path. "
             "Sunlight glistens off the water illuminating the area well."
            );
  SetNightLong(
             "A small, wooden bridge crosses overtop of a creek here in "
             "Jidoor Forest. The forest is filled with trees that tend to "
             "block travel in more directions then not, but it would be "
             "easy to travel north and south along the path from here. "
             "Moonlight glistens off the water illuminating the area well."
              );
  SetItems( ([ 
            ({"bridge"}) : "This small wooden bridge crosses overtop a "
                           "small creek.",
            ({"creek", "stream"}) : "The small creaks flows from "
                           "somewhere west of here underneath the bridge "
                           "and to the southeast.",
            ({"water"}) : "In the water, goldfish and perch are lazily "
                          "swimming around.",
            ({"path"}) : "The dirt path leads south and north from the "
                         "bridge.",
            ({"tree"}) : "No one tree has any significant differences "
                         "from any of the others.",
            ({"trees"}) : "All kinds of trees can be seen all throughout "
                          "the forest, but block movement in almost every "
                          "direction.",
            ({"fish"}) : "Several fish are swimming arounds the vicinity "
                         "of the bridge and look like they would make for "
                         "good eating if you could catch one.",
            ({"goldfish", "goldfishes", "perch", "perches"}) :
                         "Several fish are swimming arounds the vicinity "
                         "of the bridge and look like they would make for "
                         "good eating if you could catch one.",
            ({"forest"}) : "The forest is all around you."
          ]) );
  SetItemAdjectives( ([ 
              "bridge" : ({"small","wooden"}),
              "forest" : ({"jidoor"}),
              "path" : ({"dirt"}),
              "water" : ({"trickling"}),
              "creek" : ({"small"}),
              "stream" : ({"small"})
                   ]) );
  SetListen( ([ 
              "default" : "The sounds of water trickling down the creek "
                          "underneath the bridge is unobtrusive.",
            ({"creek","stream"}) : "The creek makes the most noise in the "
                          "area as it quietly flows through the forest."
           ]) );
  SetSmell( ([ 
              "default" : "The smell of fish is prevalent here.",
              "fish" : "The area simply smells like fish because of the "
                       "abundance of them in the stream."
          ]) );
  SetExits( ([ 
              "north" : d_room + "/path06",
              "south" : d_room + "/path07"
          ]) );
  SetSpeed(5);
  SetFish( ([ 
              d_npc + "/perch" : 25,
              d_npc + "/goldfish" : 35,
         ]) );
  SetChance(25);
  SetInventory( ([
              d_npc + "/lazy_fisher" : 1
              ]) );
  SetMaxFishing(3);
  }

/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: path04.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: This is the fourth part of the path leading to the keep.
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
  SetShort("a path in Jidoor Forest");
  SetDayLong(
            "The path continues southeast and west of here. The sunlight "
            "shines brightly through the trees creating a calm and peaceful "
            "atmosphere. Attached to a nearby tree is a small wooden sign. "
            "The rest of the trees in the forest calmly sway in the wind "
            "while the larger ones moan about being bothered. Branches, "
            "leaves, and flowers are strewn about the forest but the path "
            "itself is devoid of debris or flowers and looks well kept."
            );
  SetNightLong(
            "This small path runs southeast and west through Jidoor Forest. "
            "Trees are visible in all directions with branches and some "
            "debris not far from the path. A nearby tree has a small sign "
            "on it. The moonlight shines brightly through the trees from "
            "overhead. To the west, you can see lights shining in the sky "
            "not too far from the ground."
            );
  SetItems( ([ 
          ({"path"}) : "The dirt path running though the forest runs "
               "southeast and west from here.",
          ({"trees"}) : "All kinds of trees can be seen all throughout the "
               "forest.",
          ({"ground"}) : "The ground is there, just like you'd expect it to "
               "be.",
          ({"keep"}) : "The keep lies west of here but is mostly hidden by "
               "dozens of trees.",
          ({"forest", "jidoor forest"}) : "The forest is all around you.",
          ({"lights", "light"}) : "Lights are shining from the distance but "
               "you cannot make out there source this vantage point.",
          ({"air"}) : "The air? No one can see that",
          ({"sign"}) : "The sign has some writing on it.  Perhaps you might "
               "read it.",
          ({"tree", "tree with sign"}) : "One tree stands out in "
               "particuliar because it has a small sign on it.",
          ({"branches"}) : "Dead branches lie on the ground in several "
               "areas.",
          ({"branch"}) : "There are many branches lying about but none of "
               "any more interest then the others.",
          ({"debris"}) : "There is no forest debris lying near or on the "
               "path but it is quite visible throughout the forest.",
          ({"leaf"}) : "There are many leaves lying in the forest, none any "
               "more interesting than any other.",
          ({"leaves"}) : "The leaves littering the sides of the path are in "
               "a constant state of motion as the wind blows them further "
               "along the path in both directions.",
          ({"flower", "wildflower"}) : "Of the many wildflower growing all "
               "over the forest, it's difficult to decide which flower to "
               "examine more closely.",
          ({"flowers", "wildflowers"}) : "Wildflowers grow all over the "
               "forest."
          ]) );
 SetItemAdjectives( ([ 
            "path" : ({ "small", "dirt","well kept" }),
            "forest" : ({ "jidoor" }),
            "branches" : ({ "dead" }),
            "leaves" : ({ "rustling" }),
            "light" : ({"shining"}),
            "lights" : ({"shining"}),
            "sign" : ({ "wooden", "small" }),
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
          ({"wildflower","flower"}) : "The wildflowers smell as wonderful "
               "as the scent of a beautiful goddess.",
            "keep" : "Smell the keep from here? Um, no.",
            "air" : "It smells very fresh."
          ]) );
  SetRead("sign", 
            "%^GREEN%^West %^RESET%^------> %^GREEN%^P'alirith's Keep%^RESET%^\n"
            "%^GREEN%^Southeast %^RESET%^-> %^GREEN%^Jidoor Road%^RESET%^");
  SetInventory( ([ 
             d_npc + "/m_jidoor_bird" : 1,
             d_npc + "/f_jidoor_bird" : 1
              ]) );
  SetExits( ([
             "southeast" : d_room + "/path03",
             "west" : d_room + "/path05"
          ]) );
  }

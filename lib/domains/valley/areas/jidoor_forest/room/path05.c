/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: path05.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: This is the final part of the path leading to the keep.
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
  SetShort("outside a keep in Jidoor Forest");
  SetDayLong(
             "The path ends here at gatehouse of a small keep. From here, "
             "three of the obvious four stone walls that surround a small "
             "but high tower are plainly visible. Several torches are "
             "positioned along the wall to keep the area well lit at night. "
             "The forest around the keep is filled with trees of many sizes "
             "and wildflowers grow everywhere but the path itself. The path "
             "leads east from here."
            );
  SetNightLong(
            "A twenty-five foot high wall of a small keep is here. "
            "Positioned along the eastern wall, several torches create "
            "ample lighting. In the center of the eastern wall, is an open "
            "gatehouse leads into the courtyard. A tower rises from the "
            "center of keep into the darkness of the night.");
  SetNightLight(20);
  SetItems( ([ 
          ({"path"}) : "The dirt path running though the forest runs "
               "southeast and west from here.",
          ({"trees"}) : "All kinds of trees can be seen all throughout the "
               "forest.",
          ({"tree"}) : "The forest is filled with trees, none more "
               "interesting then any of the others.",
          ({"forest"}) : "The forest lies east of here and surrounds the "
               "keep.",
          ({"ground"}) : "The ground is there, just like you'd expect it to "
               "be.",
          ({"keep"}) : "This appears to be an inhabited keep judging from "
               "the obvious effort to make it appear so.",
          ({"wind"}) : "The wind? No one can see that!",
          ({"air"}) : "The air? No one can see that!",
          ({"gatehouse"}) : "The gatehouse lies in the center of the "
               "eastern wall of the keep but is wide open as if inviting of "
               "visitors. Either that, or the occupant isn't fearful of "
               "potential dangers.",
          ({"stone"}) : "The stone walls of the keep and the tower are dark "
               "and aged. The seem to be darken with soot.",
          ({"stones"}) : "The stones used to build the massive wall and the "
               "tower are dark and aged. They actually appear to be dark "
               "with soot.",
          ({"torches"}) : "The torches keep the area well lit at night.",
          ({"oil"}) : "Where is the oil?",
          ({"oil on torches"}) : "The oil on the torches is what keeps them "
               "lit.",
          ({"courtyard"}) : "The courtyard isn't very visible here. Perhaps "
               "going east would give a better view.",
          ({"wall", "east wall", "eastern wall"}) : "The east wall of the "
               "keep has a gatehouse in the center but is darker than the "
               "other walls of the keep.", 
          ({"wall", "north wall", "northern wall" }) : "The north wall is "
               "made of dark and aged stone.", 
          ({"wall", "south wall", "southern wall" }) : "The south wall is "
               "made of dark and aged stone.", 
          ({"wall", "west wall", "western wall" }) : "The western wall is "
               "barely visible by looking through the gatehouse. It looks "
               "similiar to the others.",
          ({"walls"}) : "The entire keep is surrounded by a large wall "
               "raising nearly twenty-five feet in the air. The walls of "
               "the keep appear to be made of stones and they look dark "
               "and aged. Surprisingly, there are no leaves blown up "
               "against the base of the eastern section of the wall, just "
               "wildflowers.",
          ({"tower"}) : "Although you can only see the top half of the "
               "tower, it appears to lie directly in the center of the "
               "walls surrounding the keep. Like the walls of the keep, the "
               "tower is made of aged looking stones.",
          ({"leaves"}) : "The leaves littering the sides of the path are in "
               "a constant state of motion as the wind blows them further "
               "along the path in both directions.",
          ({"leaf"}) : "The forest is scattered with leaves.  None more "
               "interesting than any of the others.",
          ({"flowers", "wildflowers"}) : "Wildflowers grow all over the "
               "forest and against the base of the keep's walls.",
          ({"flower", "wildflower"}) : "There are hundreds or thousands of "
               "flowers of many differnt types. It would be hard to pick "
               "just one.",
            ]) );
 SetItemAdjectives( ([ 
            "path" : ({ "small", "dirt", "ending", "end of" }),
            "forest" : ({ "jidoor" }),
            "leaves" : ({ "rustling", "echoing" }),
            "wall" : ({ "stone", "entire", "dark", "aged"}),
            "east wall" : ({ "stone", "entire", "dark", "aged" }),
            "eastern wall" : ({ "stone", "entire", "dark", "aged" }),
            "north wall" : ({ "stone", "entire", "dark", "aged" }),
            "northern wall" : ({ "stone", "entire", "dark", "aged" }),
            "west wall" : ({ "stone", "entire", "dark", "aged" }),
            "western wall" : ({ "stone", "entire", "dark", "aged"}),
            "south wall" : ({ "stone", "entire", "dark", "aged"}),
            "southern wall" : ({ "stone", "entire", "dark", "aged"}),
            "gatehouse" : ({ "open", "center" }),
            "torches" : ({ "several", "positioned" }),
            "tower" : ({ "aged", "stone" }),
            "oil" : ({"burnt", "torch"}),
            "stone" : ({ "aged", "dark" }),
            "stones" : ({ "aged", "dark" }),
            "keep" : ({ "small", "stone" }),
            "air" : ({ "fresh" }),
            "wind" : ({ "whistling", "echoing", "ringing" }),
            "trees" : ({"massive","larger","smaller","creaking","moaning" }),
            "tree" : ({"massive","larger","smaller","creaking", "moaning" })
                 ]) );
  SetListen( ([ 
            "default" : "The sounds of trees creaking and leaves rustling "
                "echo around you.\n"
                "The wind itself rings in your ears as it moves around the "
                "wall of the keep.",
            "trees" : "The older trees are moaning as they fight the wind.",
            "wind" : "The wind creates erie echoes through the area as it "
                "whistles through the keep.",
            "leaves" : "The sounds of the leaves rustling grows quite loud "
                "at times."
           ]) );
  SetSmell( ([ 
            "default" : "Besides the smell of fresh air, you can catch a "
                "faint smell of burnt oil.\n"
                "The smell of wildflowers is very strong here.",
            "oil" : "The smell of the oil seems to come from within keep or "
                "perhaps the torches along the wall.",
          ({"wildflowers","flowers"}) : "The wildflowers smell as wonderful "
                "as the scent of a beautiful goddess.",
          ({"wildflower","flower"}) : "The wildflowers smell as wonderful as "
                "the scent of a beautiful goddess.",
            "tower" : "Smell the tower from here?  Um, no.",
            "torches" : "The torches smell of oil.",
            "wind" : "The wind carries with it no unusual scents.",
            "keep" : "The eastern wall of the keep smells charred.",
            "walls" : "The eastern wall of the keep smells charred.",
            "oil" : "The smell of oil seems to be coming from the torches.",
            "oil on torches" : "The smell of oil is indeed coming from the "
                "torches.",
          ({"east wall", "eastern wall" }) : "The eastern wall of the keep "
                "smells especially charred.",
          ({"south wall", "southern wall" }) : "The southern wall of the "
                "keep smells charred.",
          ({"west wall", "western wall" }) : "The western wall of the keep "
                "is too far away to smell from here.",
          ({"north wall", "northern wall" }) : "The northern wall of the "
                "keep smells charred.",
            "stones" : "The stones in the eastern wall of the keep smells "
                "charred.",
            "stone" : "The stone used in the eastern wall of the keep "
                "smells charred.",
            "air" : "It smells very fresh."
/* ----------------------------------------------------------------------- */
/* I noticed in this code that you must set seperate smells for items that 
are declared seperately in SetItems() because the smells will not work using 
arrays. I also think you may not group more then two smells in an array for 
some reason and that's why wall, and the eastern and east wall are seperated
 and so forth with the other walls. */
/* ----------------------------------------------------------------------- */
            ]) );
  SetExits( ([
            "east" : d_room + "/path04",
            "west" : d_room + "/courtyard01"
          ]) );
  }

/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: courtyard01.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1997
// Abstract: This is the courtyard of P'alirith's Keep.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 25th, 1998 - Cleaned up enters.
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <domains.h>
#include "../jidoor_forest.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("the courtyard of a keep");
  SetDayLong(
            "In this small keep's courtyard, a massive tower is plainly "
            "visible here rising high into the sky. Spaced evenly around a "
            "large tower are unlit torches. The entrance to the tower is "
            "through an archway at the base of the tower. The tower itself, "
            "is surrounded by four walls all connected together.  The "
            "eastern wall contains a small gatehouse that leads east into "
            "Jidoor Forest. Sunlight streams down from above illuminating "
            "the area in a hazy yellow glow."
            );
  SetNightLong(
            "The dark sky above the small keep glistens with stars and "
            "other items of the cosmos. A huge dark tower looms overhead "
            "blocking the field of view. Torches placed evenly around the "
            "base of the tower are burning furiously trying to keep the "
            "area well lit at this time of night. Of the four walls "
            "surrounding the keep, the eastern one has the only item of "
            "interest with an open gatehouse directly in the center "
            "leading east into the forest.  At the base of the tower is an "
            "open archway through which, one could enter the tower. "
              );
  SetItems( ([ 
          ({"ground"}) : "The ground mostly consists of grass except for "
                      "a small path leading from the gatehouse to the "
                      "archway of the tower.",
          ({"forest"}) : "The forest is barely visbile by looking through "
                      "the gatehouse.",
          ({"gatehouse"}) : "The gatehouse in the eastern wall is wide "
                      "open.",
          ({"path"}) : "A small dirt path leads from the gatehouse to the "
                      "archway at the base of the tower.",
          ({"oil"}) : "Where is the oil?",
          ({"oil on torches"}) : "The oil on the torches is what keeps "
                     "them lit.",
          ({"walls"}) : "The walls of the keep are dark and aged.",
          ({"wall", "east wall", "eastern wall"}) : 
                     "The east wall of the keep has a gatehouse in the "
                     "center.", 
          ({"wall", "north wall", "northern wall" }) : 
                     "The north wall is made of dark and aged stone.", 
          ({"stone"}) : "The stone walls of the keep and the tower are "
                     "dark and aged. The seem to be darkened with soot.",
          ({"stones"}) : "The stones used to build the massive wall and "
                     "the tower are dark and aged. On closer inspection, "
                     "they actually appear to be covered with soot.",
          ({"wall", "south wall", "southern wall" }) : 
                    "The south wall is made of dark and aged stone.", 
          ({"wall", "west wall", "western wall" }) : 
                    "The western wall is made of dark and aged stone.",
          ({"grass"}) : "The courtyard is mainly filled with grass except "
                    "for the small path leading from the gatehouse to the "
                    "archway of the tower.",
          ({"torches", "torch"}) : "Torches are placed evenly around the "
                    "base of the tower. They keep the courtyard well lit "
                    "at night.",
          ({"stars"}) : "Billions of stars are visible in the night sky "
                    "except for the portion of the sky blocked by the "
                    "tower looming overhead.",
          ({"star"}) : "Many stars are in the sky, deciding on one to "
                    "look at would be hard.",
          ({"wind"}) : "The wind? No one can see that!",
          ({"glow"}) : "The stones of the keep have an yellow glow from "
                    "the sunlight.",
          ({"courtyard"}) : "The courtyard is surrounded by four massive "
                    "walls and in the center stands a dark and aged tower.",
          ({"archway","tower","keep","base"}) : "Here in the center of the "
                    "keep, a tower rises nearly fifty feet into the air "
                    "and looks ominous against the backdrop of the sky. At "
                    "the base of the tower a small archway leads into "
                    "the tower."
          ]) );
 SetItemAdjectives( ([ 
            "tower" : ({"stone","dark","aged","massive","black","looming"}),
            "gatehouse" : ({"open","small"}),
            "forest" : ({"jidoor"}),
            "glow" : ({"yellow","hazy"}),
            "keep" : ({"small"}),
            "archway" : ({"open"}),
            "torches" : ({"unlit"}),
            "stone" : ({"aged","dark"}),
            "stones" : ({"aged","dark"}),
            "wall" : ({"stone","twenty-five foot high","entire","dark",
                       "aged"}),
            "east wall" : ({"stone","twenty-five foot high","entire","dark",
                       "aged"}),
            "eastern wall" : ({"stone","twenty-five foot high","entire",
                       "dark","aged"}),
            "north wall" : ({"stone","twenty-five foot high","entire",
                       "dark","aged"}),
            "northern wall" : ({"stone","twenty-five foot high","entire",
                       "dark","aged"}),
            "west wall" : ({"stone","twenty-five foot high","entire","dark",
                       "aged"}),
            "western wall" : ({"stone","twenty-five foot high","entire",
                       "dark","aged"}),
            "south wall" : ({"stone","twenty-five foot high","entire",
                       "dark","aged"}),
            "southern wall" : ({"stone","twenty-five foot high","entire",
                       "dark","aged"})
                  ]) );
  SetListen( ([ 
            "default" : "The wind weaving it's way through the keep is the "
                     "loudest noise about." ,
            "wind" : "The wind creates erie echoes through the area as it "
                     "whistles through the keep."
           ]) );
  SetSmell( ([ 
            "default" : "The smell of oil is prevalent here but fresh grass "
                     "mixes with it to keep the scent relatively pleasant.",
            "tower" : "The tower smells charred.",
            "torches" : "The torches smell of oil.",
            "keep" : "The eastern wall of the keep smells charred.",
            "walls" : "The eastern wall of the keep smells charred.",
            "oil" : "The smell of oil seems to be coming from the torches.",
            "oil on torches" : "The smell of oil is indeed coming from the "
                     "torches.",
            "stones" : "The stones in the eastern wall of the keep smells "
                     "charred.",
            "stone" : "The stone used in the eastern wall of the keep "
                     "smells charred.",
          ({"east wall", "eastern wall" }) : "The eastern wall of the keep "
                     "smells especially charred.",
          ({"south wall", "southern wall" }) :
                     "The southern wall of the keep smells charred.",
          ({"west wall", "western wall" }) : 
                     "The western wall of the keep smells charred.",
          ({"north wall", "northern wall" }) : 
                     "The northern wall of the keep smells charred."
          ]) );
  SetExits( ([
             "east" : d_room + "/path05",
             "west" : VALLEY_VIRTUAL "valley/0,9",
          ]) );
  SetEnters( ([
             "tower" : d_room + "/tower01",
           ]) );
  }

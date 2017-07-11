#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("on the upper floor of a hospital");
   SetLong("The hospital room seems less sterile and empty of all "
           "that one clings on to in life because of the windows.  "
           "They look out onto a world of trees and green growing "
           "things and sometimes even the sky, high up above.  "
           "Inside the room are the basic white walls and beds "
           "found in any hospital, with the room continuing on "
           "to the east.");
   SetItems( ([
                ({ "eclat hospital","hospital","room","hospital room" }) :
                   (: GetLong :),
                ({ "world of trees","world","tree","trees","green",
                   "sky","windows","window" }) :
                   "The windows look out into the world outside, where "
                   "nothing is cleaned off day by day and everything "
                   "is given room to flourish if it has the life to "
                   "fight for it.",
                ({ "basic white walls","walls","wall","ceiling",
                   "floor" }) :
                   "The walls are plain and white, scrubbed clean each "
                   "day to remain so spotless.  Up at the point where "
                   "they meet the ceiling, little golden balls regulate "
                   "the amount of light the room will recieve, keeping "
                   "it constant despite the changing light of the "
                   "outside world.",
                ({ "little golden balls","gold","balls","ball" }) :
                   "The balls hang next to the ceiling and walls, "
                   "giving off light at varying amounts to get the "
                   "general atmosphere constant.",
                ({ "rows of white beds","beds","bed","rows","row" }) :
                   "The beds are lined up in neat, organized rows "
                   "that fill the room, leaving little space for "
                   "other ventures, but it seems to be enough.",
           ]) );
   SetItemAdjectives( ([
                         "basic white walls" : ({ "basic","white","plain",
                                                  "clean","spotless" }),
                         "little golden balls" : ({ "little","golden" }),
                         "rows of white beds" : ({ "row of","rows of",
                                                   "white","clean",
                                                   "neat","organized" }),
                    ]) );
   SetSmell( ([
                "default" : "The room smells clean and white.",
           ]) );
   SetListen( ([
                 "default" : "The forest gives off some amount of "
                    "noise, but little makes it through the walls of "
                    "the hospital.  Instead, the major sounds of the "
                    "room are the nearby groans of patients.",
            ]) );
   SetExits( ([
                "east" : H_ROOM + "up1",
           ]) );
   SetInventory( ([
                    H_NPC + "patientp" : 3,
                    H_NPC + "patient" : 1,
                    H_NPC + "doc_a" : 1,
                    H_NPC + "doc_b" : 1,
               ]) );
}

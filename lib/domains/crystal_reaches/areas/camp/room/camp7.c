
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("Only one wagon is in this "
           "area of the camp.  With all the trash strewn "
           "about the area, it is easy to see why the other "
           "gypsies avoid living in the same general area. "
           "Scraps of meat have been left to rot on dirty "
           "plates.  Dirty laundry and toys are piled up "
           "everywhere.  ");
    SetNightLong("The occupants of the red wagon "
           "don't have room for even a small fire with all "
           "the rubbish piled up.  Scraps of meat have "
           "been left to rot on dirty plates.  Dirty laundry "
           "and toys are piled up everywhere.  No wonder"
           " the wagon does not have a neighbor.  ");  
    SetItems( ([
             ("camp","area") : (: GetLong :),
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "land", "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "red wagon", "wagon"}):
                "The wagon appears to be a soft red with "
                "pale green trim.  The window has small "
                "shutters in a very dirty white. The back "
                "door hangs from one edge and the driver's"
                " seat is splintered.  ",
        ({"trim"}) : "Pale green trim lines the wagon. ",
        ({"shutters", "shutter"}) :
             "The dirty shutters have a few "
             "small spots that are clean enough to show "
             "that the shutters are white. ",
        ({"door"}) : "The door is broken and can not "
            "be closed.  ",
       ({"seat"}) : "The driver's seat is so splintered "
            "that it must be very uncomfortable to "
            "be the driver. ", 
        ({"trash", "rubbish"}) :  
                "Anything that could be left outside has "
                "been, including chamber pots.  ",
         ({"scraps", "scraps of meat", "meat", "scrap"}):
                "The meat looks like it may have once "
                "been dinner for the gypsies.  Now it "
                "is dinner for the maggots. ",
         ({"maggots", "maggot"}) :
               "Masses of small white "
               "maggots crawl all over the meat. ",
         ({"plates", "plate"}) : 
               "The plates are so dirty the "
               "color cannot be determined. ",
         ("laundry") :
               "Apparently the occupants of this wagon "
               "prefer to make new clothes rather than "
               "wash them. ",
       ({"toys",  "dolls", "bows", "toy", "doll", "bow"}) :
               "The toys have definitely been played with. "
               " Several of the dolls are missing limbs, and "
               "the child-sized bows are broken.  ",
         ({"chamber pots", "pots", "pot"}):
               "The chamber pots reek too strongly to get "
               "a closer look.  "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "patch" : ({"large", "dry"}),
                    "laundry" : ({"dirty"}),
                    "plates" : ({"dirty"}),
                    "trim" : ({"pale green", "green"}),
                    "shutters" : ({"small"}),
                    "door" : ({"back"}),
                    "seat" : ({"driver's", "splintered"})             
                    ]) );
    SetSmell( ([
                "default" : "Unlike the rest of the camp, "
                                  "this area stinks like a pig sty.  "
              ]) );
    SetListen( ([
                "default" :  "The screaming of a neglected "
                                  "baby drones out all other "
                                  "sounds. "
             ]) );
    SetInventory( ([ C_NPC + "man2" : 1]) );
    SetClimate("temperate");
    SetExits( ([
                       "west" : C_ROOM + "camp8",
                       "south" : C_ROOM + "camp4",
                       "southwest" : C_ROOM + "camp5"
                  ]) );
    SetEnters( ([
                "red wagon" : C_ROOM + "wagon14",
                    ]) );
}
